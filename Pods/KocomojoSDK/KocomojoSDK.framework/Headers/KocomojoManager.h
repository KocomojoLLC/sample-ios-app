//
//  KocomojoManager.h
//  KocomojoSampleApp
//
//  Created by Stanislav Krasnoyarov on 03/03/15.
//  Copyright (c) 2015 Kocomojo. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "KMLocationManagerDelegate.h"

@import NotificationCenter;

@class KMPromotion, KMReward, KMPromotionState;


@protocol KocomojoManagerDelegate <NSObject>

@optional
- (void)didEnterPromotionBoundary:(KMPromotion *)promotion;
- (void)didExitPromotionBoundary:(KMPromotion *)promotion;
- (void)didEnterCheckInBoundary:(KMPromotion *)promotion;
- (void)didExitCheckInBoundary:(KMPromotion *)promotion;

- (void)checkInDidBecomeAvailable:(KMPromotion *)promotion;

@end


@interface KocomojoManager : NSObject<KMLocationManagerDelegate, NSSecureCoding>

@property (weak, nonatomic) id<KocomojoManagerDelegate> delegate;
@property (copy, nonatomic) NSString *appId;

+ (instancetype)sharedManager;

- (void)retrieveNearbyPromotions:(void (^)(NSArray *promotions, NSError *error))completion;

- (void)startTracking;
- (void)stopTracking;

- (void)checkIn:(KMPromotion *)promotion completion:(void (^)(KMPromotionState *promotionState, NSError *error))completion;

- (void)didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;
- (void)didReceiveLocalNotification:(UILocalNotification *)notification;

@end
