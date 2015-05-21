//
//  KMBoundary.h
//  KocomojoSampleApp
//
//  Created by Stanislav Krasnoyarov on 05/03/15.
//  Copyright (c) 2015 Kocomojo. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    KMBoundaryTypeNone,
    KMBoundaryTypePromotion,
    KMBoundaryTypeCheckIn
} KMBoundaryType;

@class KMPromotion;

@interface KMBoundary : NSObject<NSSecureCoding, NSCopying>

@property (assign, nonatomic) NSUInteger type;
//@property (copy, nonatomic) NSString *promotionUUID;
@property (assign, nonatomic) NSUInteger promotionId;
//@property (strong, nonatomic) KMPromotion *promotion;
@property (strong, nonatomic) NSArray *regions;
@property (strong, nonatomic) NSArray *beaconRegions;

- (BOOL)isEqualToBoundary:(KMBoundary *)boundary;

@end
