//
//  Promotion.h
//  KocomojoSampleApp
//
//  Created by Stanislav Krasnoyarov on 03/03/15.
//  Copyright (c) 2015 Kocomojo. All rights reserved.
//

#import <Foundation/Foundation.h>

@class KMReward, KMBoundary, KMPromotionState;

@interface KMPromotion : NSObject<NSSecureCoding>

@property (assign, nonatomic) NSUInteger promotionId;

@property (copy, nonatomic) NSString *title;
@property (copy, nonatomic) NSString *tagline;
@property (copy, nonatomic) NSString *descriptionText;
@property (copy, nonatomic) NSString *imageUrl;
@property (copy, nonatomic) NSString *videoUrl;  // TODO: add to the front-end
@property (copy, nonatomic) NSString *supplementaryImageUrl; // TODO: add to the front-end
@property (copy, nonatomic) NSString *legal;
@property (copy, nonatomic) NSString *notification;

@property (strong, nonatomic) KMReward *reward;

//@property (strong, nonatomic) NSArray *boundaries;
@property (copy, nonatomic) NSString *templateId;

// reward criteria
@property (assign, nonatomic) BOOL sameLocationOnly;
@property (assign, nonatomic) NSUInteger checkInsCountRequired;
@property (assign, nonatomic) NSUInteger timeOnPropertySpentMin;
@property (assign, nonatomic) NSUInteger checkInIntervalWeeks; // check-ins should be dones within this interval

@property (strong, nonatomic) KMPromotionState *state;

@end
