/* Copyright (c) 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_COMPONENTS_BRAVE_GCM_DRIVER_BRAVE_GCM_CHANNEL_STATUS_SYNCER_H_
#define BRAVE_COMPONENTS_BRAVE_GCM_DRIVER_BRAVE_GCM_CHANNEL_STATUS_SYNCER_H_

#include <string>

#include "components/gcm_driver/gcm_channel_status_syncer.h"

namespace network {
class SharedURLLoaderFactory;
}

namespace gcm {

class BraveGCMChannelStatusSyncer : public GCMChannelStatusSyncer {
 public:
  BraveGCMChannelStatusSyncer(
      GCMDriver* driver,
      PrefService* prefs,
      const std::string& channel_status_request_url,
      const std::string& user_agent,
      scoped_refptr<network::SharedURLLoaderFactory> url_loader_factory);

  static bool IsGCMEnabled();
};

}  // namespace gcm

#endif  // BRAVE_COMPONENTS_BRAVE_GCM_DRIVER_BRAVE_GCM_CHANNEL_STATUS_SYNCER_H_
