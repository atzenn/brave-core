/* Copyright (c) 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "components/gcm_driver/gcm_driver_desktop.h"

#include "brave/components/brave_gcm_driver/brave_gcm_channel_status_syncer.h"

#define GCMChannelStatusSyncer BraveGCMChannelStatusSyncer
#include "../../../../components/gcm_driver/gcm_driver_desktop.cc"
#undef GCMChannelStatusSyncer
