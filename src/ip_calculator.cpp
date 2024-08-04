#include <node.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <sstream>
#include <iomanip>

#pragma comment(lib, "Ws2_32.lib")

using namespace v8;

std::string intToIp(uint32_t ipAddr) {
    struct in_addr addr;
    addr.s_addr = htonl(ipAddr);
    return inet_ntoa(addr);
}

std::string maskToString(uint32_t mask) {
    return intToIp(mask);
}

void CalculateIP(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();

    if (args.Length() < 2 || !args[0]->IsString() || !args[1]->IsUint32()) {
        isolate->ThrowException(Exception::TypeError(
            String::NewFromUtf8(isolate, "Wrong arguments").ToLocalChecked()));
        return;
    }

    String::Utf8Value ip(isolate, args[0]);
    uint32_t prefix = args[1]->Uint32Value(isolate->GetCurrentContext()).ToChecked();

    // Buffer to hold the result
    char result[256];

    // Use WinSock functions to calculate network address
    sockaddr_in sa;
    inet_pton(AF_INET, *ip, &(sa.sin_addr));
    uint32_t mask = 0xFFFFFFFF << (32 - prefix);
    uint32_t ipAddr = ntohl(sa.sin_addr.s_addr);
    uint32_t network = ipAddr & mask;
    uint32_t broadcast = network | ~mask;

    snprintf(result, sizeof(result), "IP: %s, Network: %s, Broadcast: %s, SubnetMask: %s",
        *ip,
        intToIp(network).c_str(),
        intToIp(broadcast).c_str(),
        maskToString(mask).c_str());

    args.GetReturnValue().Set(String::NewFromUtf8(isolate, result).ToLocalChecked());
}

void Initialize(Local<Object> exports) {
    NODE_SET_METHOD(exports, "calculateIP", CalculateIP);
}

NODE_MODULE(addon, Initialize)
