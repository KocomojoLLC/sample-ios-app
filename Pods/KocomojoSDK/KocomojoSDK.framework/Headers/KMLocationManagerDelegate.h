//
//  KMLocationManagerDelegate.h
//  KocomojoSampleApp
//
//  Created by Stanislav Krasnoyarov on 24/03/15.
//  Copyright (c) 2015 Kocomojo. All rights reserved.
//

@class KMBoundary, CLLocation;

@protocol KMLocationManagerDelegate <NSObject>

- (void)didDetermineLocation:(CLLocation *)location;
- (void)didSignificantLocationChange:(CLLocation *)location;

- (void)didEnterBoundary:(KMBoundary *)boundary;
- (void)didExitBoundary:(KMBoundary *)boundary;

@end
