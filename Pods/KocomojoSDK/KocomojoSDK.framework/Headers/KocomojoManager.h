//
//  KocomojoManager.h
//  KocomojoSampleApp
//
//  Created by Stanislav Krasnoyarov on 03/03/15.
//  Copyright (c) 2015 Kocomojo. All rights reserved.
//

#import <Foundation/Foundation.h>

@import NotificationCenter;

@class KMPromotion, KMReward, KMPromotionState;
@protocol KocomojoManagerDelegate;



/**
 The `KocomojoManager` class provides an API to retrieve nearby promotions and get notified when a check-in action becomes available.
 
 ## Usage

 Insert the following lines into `applicationDidFinishLaunchingWithOptions:` method:
 
    [KocomojoManager sharedManager].apiKey = @"<< your api key >>";
    [KocomojoManager sharedManager].delegate = self;
    [[KocomojoManager sharedManager] startTracking];
 
 */
@interface KocomojoManager : NSObject

/**
 The delegate object to receive check-in events
 */
@property (weak, nonatomic) id<KocomojoManagerDelegate> delegate;

/** 
 The API Key
 */
@property (copy, nonatomic) NSString *apiKey;

/**
 The root view controller used to present html promotions
 */
@property (weak, nonatomic) UIViewController *rootViewController;

/**
 Returns the shared manager instance.

 @return The shared manager instance.
 */
+ (instancetype)sharedManager;

/**
 Retrieve nearby promotions using current location and beacons in range

 @param completion The completion handler to call when the promotions are received

 */
- (void)retrieveNearbyPromotions:(void (^)(NSArray *promotions, NSError *error))completion;

/**
 Start tracking promotion boundaries
 */
- (void)startTracking;

/**
 Stop tracking promotion boundaries
 */
- (void)stopTracking;

/**
 Execute check-in action for the promotion

 @param promotion  A promotion to check-in
 @param completion The completion handler to call when check-in is executed
 */
- (void)checkIn:(KMPromotion *)promotion completion:(void (^)(KMPromotionState *promotionState, NSError *error))completion;

/**
 Execute check-in activation action for the promotion

 @param promotion  A promotion to check-in
 @param completion The completion handler to call when check-in activation is executed
 */
- (void)activateCheckIn:(KMPromotion *)promotion completion:(void (^)(BOOL success, NSError *error))completion;

/**
 Show promotion with html layout
 
 @param promotion  A promotion to show
 */
- (void)showPromotionWithHtmlLayout:(KMPromotion *)promotion;

- (void)didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;
- (void)didReceiveLocalNotification:(UILocalNotification *)notification;

@end


/**
 The KocomojoManagerDelegate protocol describes the methods that KocomojoManager singletone calls on its delegate
 */
@protocol KocomojoManagerDelegate <NSObject>

@optional
/**
 Tells the delegate that check-in action became available

 @param promotion A promotion for which the check-in action became available
 */
- (void)checkInDidBecomeAvailable:(KMPromotion *)promotion;

/**
 Tells the delegate that check-in activation action became available

 @param promotion A promotion for which the check-in activation action became available
 */
- (void)checkInActivationDidBecomeAvailable:(KMPromotion *)promotion;

@end

