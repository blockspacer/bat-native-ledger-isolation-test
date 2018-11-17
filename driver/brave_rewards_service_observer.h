 /* This Source Code Form is subject to the terms of the Mozilla Public
  * License, v. 2.0. If a copy of the MPL was not distributed with this file,
  * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_REWARDS_SERVICE_OBSERVER_H_
#define BRAVE_REWARDS_SERVICE_OBSERVER_H_

#include "bat/ledger/grant.h"
#include "bat/ledger/publisher_info.h"
#include "content_site.h"
#include "publisher_banner.h"
#include "wallet_properties.h"

namespace brave_rewards {

class BraveRewardsService;

class BraveRewardsServiceObserver {
 public:
  virtual ~BraveRewardsServiceObserver() {}

  virtual void OnWalletInitialized(BraveRewardsService* payment_service,
                               int error_code) {};
  virtual void OnWalletProperties(
    BraveRewardsService* rewards_service,
    int error_code,
    std::unique_ptr<brave_rewards::WalletProperties> properties) {
  };
  virtual void OnGrant(BraveRewardsService* rewards_service,
    unsigned int error_code,
    ledger::Grant properties) {
  };
  virtual void OnGrantCaptcha(BraveRewardsService* rewards_service,
                              std::string image,
                              std::string hint) {};
  virtual void OnRecoverWallet(BraveRewardsService* rewards_service,
    unsigned int result,
    double balance,
    std::vector<ledger::Grant> grants) {
  };
  virtual void OnGrantFinish(BraveRewardsService* rewards_service,
    unsigned int result,
    ledger::Grant grant) {
  };
  virtual void OnContentSiteUpdated(BraveRewardsService* rewards_service) {};
  virtual void OnExcludedSitesChanged(BraveRewardsService* rewards_service) {};
  virtual void OnReconcileComplete(BraveRewardsService* rewards_service,
                                   unsigned int result,
                                   const std::string& viewing_id,
                                   const std::string& probi) {};
  virtual void OnRecurringDonationUpdated(BraveRewardsService* rewards_service,
                                          brave_rewards::ContentSiteList) {};
  virtual void OnCurrentTips(BraveRewardsService* rewards_service,
                             brave_rewards::ContentSiteList) {};
  virtual void OnPublisherBanner(BraveRewardsService* rewards_service,
                                 const brave_rewards::PublisherBanner banner) {};
  virtual void OnGetPublisherActivityFromUrl(
      BraveRewardsService* rewards_service,
      int error_code,
      ledger::PublisherInfo* info,
      uint64_t windowId) {};
};

}  // namespace brave_rewards

#endif  // BRAVE_REWARDS_SERVICE_OBSERVER_H_
