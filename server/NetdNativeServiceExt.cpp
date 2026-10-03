#include "Controllers.h"
#include "NetdNativeService.h"
#include "NetdNativeServiceExt.h"

#include "android/net/ext/BnNetdExt.h"
#include "binder_utils/BinderUtil.h"

namespace android {
namespace net {
namespace ext {

NetdNativeServiceExt::NetdNativeServiceExt() {
    // register log callback to BnNetd::logFunc
    BnNetdExt::logFunc = [](const auto& log) {
        binderCallLogFn(log, [](const std::string& msg) { gLog.info("%s", msg.c_str()); });
    };
}

binder::Status NetdNativeServiceExt::networkSetOwner(int32_t netId, int32_t uid) {
    ENFORCE_NETWORK_STACK_PERMISSIONS();

    gLog.error("networkSetOwner called, netId: %d, uid: %d", netId, uid);

    gCtls->netCtrl.networkSetOwner(netId, uid);

    return binder::Status::ok();
}

}  // namespace ext
}  // namespace net
}  // namespace android
