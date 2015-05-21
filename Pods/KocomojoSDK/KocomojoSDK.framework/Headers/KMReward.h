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

@interface KMReward : NSObject<NSSecureCoding>

@property (weak, nonatomic) KMPromotion *promotion;

@property (copy, nonatomic) NSString *header;
@property (copy, nonatomic) NSString *text;
@property (copy, nonatomic) NSString *imageUrl;
@property (copy, nonatomic) NSString *rewardImageUrl;
@property (nonatomic) KMRewardActionType actionType;

@end
