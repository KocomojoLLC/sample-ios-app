//
//  KMPromotionState.h
//  KocomojoSDK
//
//  Created by Stanislav Krasnoyarov on 02/06/15.
//  Copyright (c) 2015 Kocomojo. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface KMPromotionState : NSObject

@property (assign, nonatomic) BOOL isCheckInAvailable;
@property (assign, nonatomic) BOOL reward;
@property (assign, nonatomic) NSUInteger checkInsTotalCount;
@property (assign, nonatomic) NSUInteger checkInsCount;

@property (assign, nonatomic) NSUInteger timeOnPropertySpentMin;
@property (strong, nonatomic) NSDate *lastCheckInTimestamp;
@property (strong, nonatomic) NSDate *lastBoundaryEntryTimestamp;

@property (copy, nonatomic) NSString *checkInUnavailabilityReasonCode;
@property (copy, nonatomic) NSString *checkInUnavailabilityReasonDescription;

- (NSTimeInterval)timeLeft;
- (float)progress;
- (NSTimeInterval)timeIntervalSinceLastAreaEnterOrCheckIn;

@end
