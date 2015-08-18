//
//  KMReward.h
//  KocomojoSampleApp
//
//  Created by Stanislav Krasnoyarov on 04/03/15.
//  Copyright (c) 2015 Kocomojo. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum : NSUInteger {
    KMRewardActionNone,
    KMRewardActionPassbook
} KMRewardActionType;


@class KMPromotion;

/**
 A `KMReward` object provides information about the reward.
 */
@interface KMReward : NSObject<NSSecureCoding>

/**
 The reward promotion
 @see KMPromotion
 */
@property (weak, nonatomic) KMPromotion *promotion;

/**
 The reward title
 */
@property (copy, nonatomic) NSString *title;

/**
 The reward tagline
 */
@property (copy, nonatomic) NSString *tagline;

/**
 The reward description
 */
@property (copy, nonatomic) NSString *descriptionText;

/**
 The reward image url
 */
@property (copy, nonatomic) NSString *imageUrl;

/**
 The reward promotion code
 */
@property (copy, nonatomic) NSString *promotionCode;

/**
 The reward promotion image url
 */
@property (copy, nonatomic) NSString *promotionCodeImageUrl;

/**
 The reward layout id
 */
@property (assign, nonatomic) NSUInteger layoutId;

/**
 The reward layout name
 */
@property (copy, nonatomic) NSString *layoutName;

/**
 The reward layout type
 */
//@property (assign, nonatomic) KMLayoutType layoutType;

@end
