/* Copyright (c) 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BAT_ADS_AD_HISTORY_DETAIL_H_
#define BAT_ADS_AD_HISTORY_DETAIL_H_

#include <stdint.h>
#include <string>

#include "bat/ads/ad_content.h"
#include "bat/ads/category_content.h"
#include "bat/ads/export.h"
#include "bat/ads/result.h"

namespace ads {

struct ADS_EXPORT AdHistoryDetail {
  AdHistoryDetail();
  explicit AdHistoryDetail(const AdHistoryDetail& detail);
  ~AdHistoryDetail();

  const std::string ToJson() const;
  Result FromJson(
      const std::string& json,
      std::string* error_description = nullptr);

  uint64_t timestamp_in_seconds;
  std::string uuid;
  AdContent ad_content;
  CategoryContent category_content;
};

}  // namespace ads

#endif  // BAT_ADS_AD_HISTORY_DETAIL_H_
