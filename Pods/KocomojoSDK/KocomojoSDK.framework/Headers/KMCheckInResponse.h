//
//  KMCheckInResponse.h
//  KocomojoSampleApp
//
//  Created by Stanislav Krasnoyarov on 06/05/15.
//  Copyright (c) 2015 Kocomojo. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface KMCheckInResponse : NSObject

@property (assign, nonatomic) NSUInteger count;
@property (assign, nonatomic) NSUInteger totalCount;  // including check-ins for the past rewards
@property (assign, nonatomic) BOOL reward;             // valid for the check-ins only
@property (strong, nonatomic) NSDate *lastCheckInTimestamp;

@end
