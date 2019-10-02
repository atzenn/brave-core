/* Copyright (c) 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/components/brave_gcm_driver/brave_gcm_channel_status_syncer.h"

#include "components/prefs/pref_service.h"
#include "services/network/public/cpp/shared_url_loader_factory.h"

namespace gcm {

static bool gcm_channel_enabled_ = false;

BraveGCMChannelStatusSyncer::BraveGCMChannelStatusSyncer(
    GCMDriver* driver,
    PrefService* prefs,
    const std::string& channel_status_request_url,
    const std::string& user_agent,
    scoped_refptr<network::SharedURLLoaderFactory> url_loader_factory) :
    GCMChannelStatusSyncer(driver,
                           prefs,
                           channel_status_request_url,
                           user_agent,
                           url_loader_factory) {
    gcm_channel_enabled_ = prefs->GetBoolean(prefs::kGCMChannelStatus);
}

// static
bool BraveGCMChannelStatusSyncer::IsGCMEnabled() {
    return gcm_channel_enabled_;
}

}  // namespace gcm
