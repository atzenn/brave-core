/* Copyright (c) 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_COMPONENTS_BRAVE_GCM_DRIVER_BRAVE_GCM_CHANNEL_STATUS_SYNCER_H_
#define BRAVE_COMPONENTS_BRAVE_GCM_DRIVER_BRAVE_GCM_CHANNEL_STATUS_SYNCER_H_

#include <string>

#include "base/supports_user_data.h"
#include "components/gcm_driver/gcm_channel_status_syncer.h"

namespace network {
class SharedURLLoaderFactory;
}

class Profile;

namespace gcm {

class BraveGCMChannelStatus : public base::SupportsUserData::Data {
 public:
  explicit BraveGCMChannelStatus(bool enabled) : gcm_enabled_(enabled) {}
  bool IsGCMEnabled();

 private:
  bool gcm_enabled_;
};

class BraveGCMChannelStatusSyncer : public GCMChannelStatusSyncer {
 public:
  static BraveGCMChannelStatus* status;
  static BraveGCMChannelStatus* GetForProfile(Profile* profile);

  BraveGCMChannelStatusSyncer(
      GCMDriver* driver,
      PrefService* prefs,
      const std::string& channel_status_request_url,
      const std::string& user_agent,
      scoped_refptr<network::SharedURLLoaderFactory> url_loader_factory);

  bool IsGCMEnabled();
};

}  // namespace gcm

#endif  // BRAVE_COMPONENTS_BRAVE_GCM_DRIVER_BRAVE_GCM_CHANNEL_STATUS_SYNCER_H_
