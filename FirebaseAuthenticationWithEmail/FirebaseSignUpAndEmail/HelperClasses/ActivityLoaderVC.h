//
//  ActivityLoaderVC.h
//  FirebaseSignUpAndEmail
//
//  Created by Pragnesh Dixit on 31/08/16.
//  Copyright © 2016 Tristate Technology. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SHActivityView.h"
#import "Reachability.h"
#import "TSTAlertView.h"
#import "Constants.h"

@interface ActivityLoaderVC : UIViewController
{
    SHActivityView *spinnerMedium; // White spinner
}
@property (strong, nonatomic) IBOutlet UIView *viewOuter;
- (BOOL)isNetworkReachable;
- (void)showNoNetwokMessage;
- (void)showHud;
- (void)hideHud;
-(void)showMessage:(NSString*)message withTitle:(NSString *)title;
@end
