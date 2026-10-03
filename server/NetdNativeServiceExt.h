#ifndef _NETD_NATIVE_SERVICE_EXT_H_
#define _NETD_NATIVE_SERVICE_EXT_H_

#include <vector>

#include <binder/BinderService.h>
#include <netdutils/Log.h>

#include "android/net/ext/BnNetdExt.h"

namespace android {
namespace net {
namespace ext {

class NetdNativeServiceExt : public BnNetdExt {
  public:
    NetdNativeServiceExt();
    //static status_t start();
    static char const* getServiceName() { return "netd"; }

    binder::Status networkSetOwner(int32_t netId, int32_t uid) override;

  private:
};

}  // namespace ext
}  // namespace net
}  // namespace android

#endif  // _NETD_NATIVE_SERVICE_EXT_H_
