//
//  ActivityLoaderVC.m
//  FirebaseSignUpAndEmail
//
//  Created by Pragnesh Dixit on 31/08/16.
//  Copyright © 2016 Tristate Technology. All rights reserved.
//

#import "ActivityLoaderVC.h"

@interface ActivityLoaderVC ()

@end

@implementation ActivityLoaderVC

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
-(void)indicaterLoadDefine{
    self.viewOuter=[[UIView alloc] initWithFrame:CGRectMake(0, 0, self.view.frame.size.width, self.view.frame.size.height)];
    self.viewOuter.backgroundColor=[UIColor colorWithRed:14/255.0 green:30/255.0 blue:78/255.0 alpha:.5];
    self.viewOuter.tag=5;
    [self.view addSubview:self.viewOuter];
    spinnerMedium = [[SHActivityView alloc]init];
    spinnerMedium.centerTitle = @"75 %";
    spinnerMedium.bottomTitle = @"  Loading";
    spinnerMedium.spinnerSize = kSHSpinnerSizeMedium;
    [self.viewOuter addSubview:spinnerMedium];
}
-(void)showHud{
    dispatch_async(dispatch_get_main_queue(), ^{
        // code here
        [self indicaterLoadDefine];
        [spinnerMedium showAndStartAnimate];
        [self makeSpinnerTinyOnCenter];
    });
    
    
}
-(void)hideHud{
    dispatch_async(dispatch_get_main_queue(), ^{
        [spinnerMedium dismissAndStopAnimation];
        
        NSArray *subViews = [self.view subviews];
        for(UIView *view in subViews)
        {
            if (view.tag==5) {
                [view removeFromSuperview];
            }
        }
    });
}

- (BOOL)isNetworkReachable{
    Reachability * rechablity = [Reachability reachabilityForInternetConnection];
    
    return rechablity.isReachable;
}
-(void)showNoNetwokMessage{
    [self showMessage:@"There is no internet connection for this device"
            withTitle:@"Error"];
}

-(void)makeSpinnerTinyOnCenter
{
    spinnerMedium.center = CGPointMake(self.viewOuter.frame.size.width/2, self.viewOuter.frame.size.height/2);
}
-(void)showMessage:(NSString*)message withTitle:(NSString *)title
{
    TSTAlertView *alert = [[TSTAlertView alloc] init];
    alert.backgroundType = Blur;
    alert.showAnimationType = SlideInFromTop;
    [alert showNotice:self title:ALERT_TITLE subTitle:@"Please check your internet connection." closeButtonTitle:@"OK" duration:0.0f];

    
//    UIAlertController * alert=   [UIAlertController
//                                  alertControllerWithTitle:title
//                                  message:message
//                                  preferredStyle:UIAlertControllerStyleAlert];
//    
//    UIAlertAction *okAction = [UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleDefault handler:^(UIAlertAction *action){
//        
//        //do something when click button
//    }];
//    [alert addAction:okAction];
//    UIViewController *vc = [[[[UIApplication sharedApplication] delegate] window] rootViewController];
//    [vc presentViewController:alert animated:YES completion:nil];
}



@end
