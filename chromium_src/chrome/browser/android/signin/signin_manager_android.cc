/* Copyright (c) 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/build/android/jni_headers/BraveSigninManager_jni.h"
#include "chrome/browser/android/signin/signin_manager_android.h"
#include "chrome/android/chrome_jni_headers/SigninManager_jni.h"

namespace {
// For preventing "unused Java_SigninManager_create method" compile error.
class UnusedClass {
 private:
  void test() {
    Java_SigninManager_create(nullptr, 0ll, nullptr, nullptr);
  }
};
}  // namespace

#define Java_SigninManager_create Java_BraveSigninManager_create
#include "../../../../../../chrome/browser/android/signin/signin_manager_android.cc"  // NOLINT
#undef Java_SigninManager_create

