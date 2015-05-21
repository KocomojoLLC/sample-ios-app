//
//  Promotion.h
//  KocomojoSampleApp
//
//  Created by Stanislav Krasnoyarov on 03/03/15.
//  Copyright (c) 2015 Kocomojo. All rights reserved.
//

#import <Foundation/Foundation.h>

@class KMReward;
@class KMBoundary;

@interface KMPromotion : NSObject<NSSecureCoding>

@property (assign, nonatomic) NSUInteger promotionId;

@property (copy, nonatomic) NSString *header;    // title
@property (copy, nonatomic) NSString *blurb;     // tagline
@property (copy, nonatomic) NSString *text;      // description
@property (copy, nonatomic) NSString *imageUrl;
@property (copy, nonatomic) NSString *videoUrl;  // TODO: add to the front-end
@property (copy, nonatomic) NSString *supplementaryImageUrl; // TODO: add to the front-end
@property (copy, nonatomic) NSString *legalText; // legal
@property (copy, nonatomic) NSString *notificationText; // notification

@property (strong, nonatomic) KMReward *reward;

@property (assign, nonatomic) BOOL isCheckInAvailable;
@property (assign, nonatomic) NSUInteger checkInsTotalCount;
@property (strong, nonatomic) NSDate *lastCheckInTimestamp;
@property (strong, nonatomic) NSDate *lastBoundaryEntryTimestamp;
@property (readonly, nonatomic) NSDate *lastActionTimestamp;
@property (copy, nonatomic) NSString *checkInUnavailabilityReasonCode;
@property (copy, nonatomic) NSString *checkInUnavailabilityReasonDescription;

//@property (strong, nonatomic) NSArray *boundaries;
@property (copy, nonatomic) NSString *templateId;

// reward criteria
@property (assign, nonatomic) BOOL sameLocationOnly;
@property (assign, nonatomic) NSUInteger checkInsCountRequired;
@property (assign, nonatomic) NSUInteger timeOnPropertySpentMin;
@property (assign, nonatomic) NSUInteger checkInIntervalWeeks; // check-ins should be dones within this interval

@end
