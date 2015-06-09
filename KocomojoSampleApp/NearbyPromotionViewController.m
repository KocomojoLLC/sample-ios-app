//
//  NearbyPromotionViewController.m
//  KocomojoSampleApp
//
//  Created by Stanislav Krasnoyarov on 21/05/15.
//  Copyright (c) 2015 Kocomojo. All rights reserved.
//

#import "NearbyPromotionViewController.h"

#import <KocomojoSDK/KocomojoSDK.h>

@implementation NearbyPromotionViewController {
    NSArray *_promotions;
}

- (void)viewDidLoad {
    [super viewDidLoad];

    self.refreshControl = [UIRefreshControl new];
    [self.refreshControl addTarget:self
                            action:@selector(refresh)
                  forControlEvents:UIControlEventValueChanged];
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    
    [self.refreshControl beginRefreshing];
    [self refresh];
}

- (void)refresh {
    [[KocomojoManager sharedManager] retrieveNearbyPromotions:^(NSArray *promotions, NSError *error) {
        _promotions = promotions;
        dispatch_async(dispatch_get_main_queue(), ^{
            [self.refreshControl endRefreshing];
            [self.tableView reloadData];
        });
    }];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Table view data source

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    // Return the number of rows in the section.
    return [_promotions count];
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return _promotions ? 1 : 0;
}

//- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
//{
//    // Return the number of sections.
//    if (_promotions) {
//        self.tableView.backgroundView = nil;
////        self.tableView.separatorStyle = UITableViewCellSeparatorStyleSingleLine;
//        return 1;
//    }
//
//    // Display a message when the table is empty
//    UILabel *messageLabel = [[UILabel alloc] initWithFrame:CGRectMake(0, 0, self.view.bounds.size.width - 100, self.view.bounds.size.height)];
//    
//    messageLabel.text = @"No data is currently available. Please pull down to refresh.";
//    messageLabel.textColor = [UIColor blackColor];
////    messageLabel.backgroundColor = [UIColor lightGrayColor];
//    messageLabel.numberOfLines = 0;
//    messageLabel.textAlignment = NSTextAlignmentCenter;
////    messageLabel.font = [UIFont fontWithName:@"Palatino-Italic" size:20];
////    [messageLabel sizeToFit];
//    
//    self.tableView.backgroundView = messageLabel;
////    self.tableView.separatorStyle = UITableViewCellSeparatorStyleNone;
//    
//    return 0;
//}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"Cell" forIndexPath:indexPath];
    
    KMPromotion *promotion = _promotions[indexPath.row];
    
    cell.textLabel.text = promotion.title;
    cell.detailTextLabel.text = promotion.tagline;
    
    return cell;
}

#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.

    if ([segue.identifier isEqualToString:@"ShowPromotion"]) {
        KMPromotion *promotion = _promotions[[self.tableView indexPathForSelectedRow].row];
        [segue.destinationViewController setPromotion:promotion];
    }
}

- (IBAction)unwindToParent:(UIStoryboardSegue *)segue {
}

@end
