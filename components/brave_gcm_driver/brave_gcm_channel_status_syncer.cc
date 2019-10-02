/* Copyright (c) 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/components/brave_gcm_driver/brave_gcm_channel_status_syncer.h"

#include "base/memory/ptr_util.h"
#include "chrome/browser/profiles/profile.h"
#include "components/prefs/pref_service.h"
#include "services/network/public/cpp/shared_url_loader_factory.h"

namespace gcm {

const char kBraveGCMStatusKey[] = "brave_gcm_channel_status";
BraveGCMChannelStatus* BraveGCMChannelStatusSyncer::status = NULL;

BraveGCMChannelStatusSyncer::BraveGCMChannelStatusSyncer(
    GCMDriver* driver,
    PrefService* prefs,
    const std::string& channel_status_request_url,
    const std::string& user_agent,
    scoped_refptr<network::SharedURLLoaderFactory> url_loader_factory)
    : GCMChannelStatusSyncer(driver,
                             prefs,
                             channel_status_request_url,
                             user_agent,
                             url_loader_factory) {
  // At destruction all the objects will be cleaned up by SupportsUserData
  BraveGCMChannelStatusSyncer::status =
      new BraveGCMChannelStatus(prefs->GetBoolean(prefs::kGCMChannelStatus));
}

// static
BraveGCMChannelStatus* BraveGCMChannelStatusSyncer::GetForProfile(
    Profile* profile) {
  BraveGCMChannelStatus* status = static_cast<BraveGCMChannelStatus*>(
      profile->GetUserData(kBraveGCMStatusKey));

  if (!status) {
    profile->SetUserData(kBraveGCMStatusKey,
                         base::WrapUnique(BraveGCMChannelStatusSyncer::status));
    status = static_cast<BraveGCMChannelStatus*>(
        profile->GetUserData(kBraveGCMStatusKey));
  }

  return status;
}

bool BraveGCMChannelStatus::IsGCMEnabled() {
  return gcm_enabled_;
}

}  // namespace gcm
