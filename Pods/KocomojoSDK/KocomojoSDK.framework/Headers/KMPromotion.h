//
//  Promotion.h
//  KocomojoSampleApp
//
//  Created by Stanislav Krasnoyarov on 03/03/15.
//  Copyright (c) 2015 Kocomojo. All rights reserved.
//

#import <Foundation/Foundation.h>

@class KMReward, KMBoundary, KMPromotionState;

typedef enum : NSUInteger {
    KMLayoutUndefined,
    KMLayoutNative,
    KMLayoutHtml
} KMLayoutType;

/**
 A `KMPromotion` object provides information about the promotion.
 */
@interface KMPromotion : NSObject<NSSecureCoding>

/**
 A unique promotion identifier
 */
@property (assign, nonatomic) NSUInteger promotionId;

/**
 The promotion title
 */
@property (copy, nonatomic) NSString *title;

/**
 The promotion tagline
 */
@property (copy, nonatomic) NSString *tagline;

/**
 The promotion description
 */
@property (copy, nonatomic) NSString *descriptionText;

/**
 The promotion image url
 */
@property (copy, nonatomic) NSString *imageUrl;

/**
 The promotion video url (not implemented currently)
 */
@property (copy, nonatomic) NSString *videoUrl;

/**
 The promotion supplementary image url (not implemented currently)
 */
@property (copy, nonatomic) NSString *supplementaryImageUrl;

/**
 The promotion legal text
 */
@property (copy, nonatomic) NSString *legal;

/**
 The promotion notification text
 */
@property (copy, nonatomic) NSString *notification;

/**
 The promotion reward
 */
@property (strong, nonatomic) KMReward *reward;

/**
 The promotion layout id
 */
@property (assign, nonatomic) NSUInteger layoutId;

/**
 The promotion layout name
 */
@property (copy, nonatomic) NSString *layoutName;

/**
 The promotion layout type
 */
@property (assign, nonatomic) KMLayoutType layoutType;

// reward criteria
/**
 The promotion reward criteria which requires all check-ins to be executed at the same location
 */
@property (assign, nonatomic) BOOL sameLocationOnly;

/**
 The promotion reward criteria which defines number of check-ins required in order to receive a reward
 */
@property (assign, nonatomic) NSUInteger checkInsCountRequired;

/**
 The promotion reward criteria which defines minimum time on property spent in order to execute the check-in
 */
@property (assign, nonatomic) NSUInteger timeOnPropertySpentMin;

/**
 The promotion reward criteria which defines the sliding timeframe for the `checkInsCountRequired`
 */
@property (assign, nonatomic) NSUInteger checkInIntervalWeeks; // check-ins should be dones within this interval

/**
 The promotion state for current user
 @see KMPromotionState
 */
@property (strong, nonatomic) KMPromotionState *state;

@end
