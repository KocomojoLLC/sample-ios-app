//
//  KMPromotionState.h
//  KocomojoSDK
//
//  Created by Stanislav Krasnoyarov on 02/06/15.
//  Copyright (c) 2015 Kocomojo. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 A `KMPromotionState` object provides information about the promotion state.
 */
@interface KMPromotionState : NSObject

/**
 A Boolean indicating whether the check-in action is available
 */
@property (assign, nonatomic) BOOL isCheckInAvailable;

/**
 A Boolean indicating whether the reward was given after a check-in
 */
@property (assign, nonatomic) BOOL reward;

/**
 The number of check-ins executed since last recurrance
 */
@property (assign, nonatomic) NSUInteger checkInsCount;

/**
 The total number of check-ins executed
 */
@property (assign, nonatomic) NSUInteger checkInsTotalCount;

/**
 The promotion reward criteria which defines minimum time on property spent in order to execute the check-in
 */
@property (assign, nonatomic) NSUInteger timeOnPropertySpentMin;

/**
 The activation timestamp for promotions with time on property
 */
@property (strong, nonatomic) NSDate *activationTimestamp;

/**
 The check-in unavailability reason code
 */
@property (copy, nonatomic) NSString *checkInUnavailabilityReasonCode;

/**
 The check-in unavailability reason description
 */
@property (copy, nonatomic) NSString *checkInUnavailabilityReasonDescription;

/**
 A time left to fulfill minimum time on property criteria
 */
- (NSTimeInterval)timeLeft;

/**
 The progress of time on property criteria fulfillment
 */
- (float)progress;

/**
 A time since check-in activation
 */
- (NSTimeInterval)timeIntervalSinceActivation;

@end
