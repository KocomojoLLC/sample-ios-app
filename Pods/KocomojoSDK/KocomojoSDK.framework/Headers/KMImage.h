//
//  KMImage.h
//  KocomojoSampleApp
//
//  Created by Stanislav Krasnoyarov on 20/04/15.
//  Copyright (c) 2015 Kocomojo. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface KMImage : NSObject

@property (assign, nonatomic) NSUInteger imageId;
@property (copy, nonatomic) NSString *name;
@property (copy, nonatomic) NSString *path;
@property (assign, nonatomic) NSUInteger width;
@property (assign, nonatomic) NSUInteger height;
@property (copy, nonatomic) NSString *category;
@property (copy, nonatomic) NSString *mimeType;

@end
