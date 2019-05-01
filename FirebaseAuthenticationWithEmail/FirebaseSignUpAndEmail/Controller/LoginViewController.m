//
//  LoginViewController.m
//  FirebaseSignUpAndEmail
//
//  Created by TriState on 8/30/16.
//  Copyright © 2016 Tristate Technology. All rights reserved.
//

#import "LoginViewController.h"
#import "SignUpViewController.h"
#import <Firebase.h>
#import <FIRAuth.h>
#import <FIRUser.h>
#import <FBSDKCoreKit/FBSDKCoreKit.h>
#import <FBSDKLoginKit/FBSDKLoginKit.h>
#import <GoogleSignIn/GoogleSignIn.h>
@interface LoginViewController ()<GIDSignInUIDelegate,GIDSignInDelegate>{
    IBOutlet UITextField *tfEmailID;
    IBOutlet UITextField *tfPassword;
    IBOutlet UIImageView *imgCompanyLogo;
    IBOutlet UIButton *btnSignUp;
    IBOutlet UIButton *btnLogin;
    
    FBSDKLoginButton *loginButton;
}
@property(strong,nonatomic)IBOutlet UIScrollView *scrollView;
@property(strong,nonatomic) UITextField *txtFieldCheck;
@property(weak, nonatomic) IBOutlet GIDSignInButton *signInButton;
@end

@implementation LoginViewController

#pragma mark - View Life Cycle Methods
- (void)viewDidLoad {
    [super viewDidLoad];
    
   
    

    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(keyboardDidShow:)
                                                 name:UIKeyboardWillShowNotification
                                               object:nil];
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(keyboardWillBeHidden:)
                                                 name:UIKeyboardWillHideNotification
                                               object:nil];
    
    loginButton = [[FBSDKLoginButton alloc] init];
    if ([FBSDKAccessToken currentAccessToken]) {
        // User is logged in, do work such as go to next view controller.
        loginButton.readPermissions = @[@"public_profile", @"email"];
    }
     [GIDSignIn sharedInstance].uiDelegate = self;
}

-(void)viewWillAppear:(BOOL)animated{
    [super viewWillAppear:animated];
    self.navigationController.navigationBar.hidden = YES;
    tfEmailID.text = tfPassword.text = @"";
    
}
- (UIStatusBarStyle)preferredStatusBarStyle {
    return UIStatusBarStyleLightContent;
}
-(void)viewDidDisappear:(BOOL)animated{
    [super viewDidDisappear:animated];
    
    [[NSNotificationCenter defaultCenter] removeObserver:UIKeyboardWillShowNotification];
    [[NSNotificationCenter defaultCenter] removeObserver:UIKeyboardWillHideNotification];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - All Validation methods

-(BOOL)validation{
    NSString *strEmailID = [tfEmailID.text stringByTrimmingCharactersInSet:
                            [NSCharacterSet whitespaceCharacterSet]];
    NSString *strPassword = [tfPassword.text stringByTrimmingCharactersInSet:
                             [NSCharacterSet whitespaceCharacterSet]];
    
    if (strEmailID.length <= 0){
        [self displayAlertView:@"Please enter email Id"];
        return NO;
    }
    else if (strPassword.length <= 0){
        [self displayAlertView:@"Please enter password"];
        return NO;
    }
    else if ([self validateEmailAddress:strEmailID] == NO){
        [self displayAlertView:@"Please enter valid email Id"];
        return NO;
    }
    return YES;
}

-(BOOL)validateEmailAddress:(NSString *)checkString{
    BOOL stricterFilter = NO; // Discussion http://blog.logichigh.com/2010/09/02/validating-an-e-mail-address/
    NSString *stricterFilterString = @"^[A-Z0-9a-z\\._%+-]+@([A-Za-z0-9-]+\\.)+[A-Za-z]{2,4}$";
    NSString *laxString = @"^.+@([A-Za-z0-9-]+\\.)+[A-Za-z]{2}[A-Za-z]*$";
    NSString *emailRegex = stricterFilter ? stricterFilterString : laxString;
    NSPredicate *emailTest = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", emailRegex];
    return [emailTest evaluateWithObject:checkString];
}

#pragma mark - UITextField Delegate methods
- (BOOL)textFieldShouldBeginEditing:(UITextField *)textField{
    
    self.txtFieldCheck = textField;
    return YES;
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField{
    [textField resignFirstResponder];
    if (textField == tfEmailID){
        [tfPassword becomeFirstResponder];
    }
    return YES;
}

#pragma mark - UIAlertView  methods
-(void)displayAlertView:(NSString *)strMessage{
    TSTAlertView *alert = [[TSTAlertView alloc] init];
    alert.backgroundType = Blur;
    alert.showAnimationType = SlideInFromTop;
    [alert showError:self title:ALERT_TITLE subTitle:strMessage closeButtonTitle:@"Okay!" duration:0.0f];
}

#pragma mark - custom Methods
-(IBAction)btnLoginAction:(id)sender{
    [self.view endEditing:YES];
    if ([self validation]){
        [self showHud];
        [[FIRAuth auth] signInWithEmail:tfEmailID.text password:tfPassword.text completion:^(FIRAuthDataResult * _Nullable authResult, NSError * _Nullable error) {
            [self hideHud];
            if (error) {
                [self displayAlertView:@"Please enter valid password"];
                NSLog(@"Error in FIRAuth := %@",error.localizedDescription);
            }
            else{
                tfEmailID.text = @"";
                tfPassword.text = @"";
                TSTAlertView *alert = [[TSTAlertView alloc] init];
                alert.backgroundType = Blur;
                alert.showAnimationType = SlideInFromTop;
                [alert showSuccess:self title:ALERT_TITLE subTitle:@"Successfully login with Firebase." closeButtonTitle:nil duration:0.0f];
                [alert addButton:@"Okay" actionBlock:^{
                    
                }];
                NSLog(@"user Id : %@", authResult.user.uid);
            }
        }];
    }
}

-(IBAction)btnSignUpAction:(id)sender{
    SignUpViewController *objSignUpViewController = [self.storyboard instantiateViewControllerWithIdentifier:@"SignUpViewController"];
    [self.navigationController pushViewController:objSignUpViewController animated:YES];
}

- (IBAction)btnGoogleSignInAction:(UIButton *)sender {
    [GIDSignIn sharedInstance].delegate = self;
    [GIDSignIn sharedInstance].uiDelegate = self;
    [[GIDSignIn sharedInstance] signIn];
}


    #pragma mark - Facebook Login  Methods
- (IBAction)btnFacebookLoginAction:(UIButton *)sender {
    FBSDKLoginManager *login = [[FBSDKLoginManager alloc] init];
    [login logOut];
    [login setLoginBehavior:FBSDKLoginBehaviorBrowser];
    [login
     
     logInWithReadPermissions: @[@"email"]
     fromViewController:self
     handler:^(FBSDKLoginManagerLoginResult *result, NSError *error) {
         if (error) {
             NSLog(@"Process error");
         } else if (result.isCancelled) {
             NSLog(@"Cancelled");
         } else {
             NSLog(@"Logged in");
             [self getFacebookUserinfo];
         }
     }];
    

}
-(void)getFacebookUserinfo{
    [[[FBSDKGraphRequest alloc] initWithGraphPath:@"me"
                                       parameters:@{@"fields": @"picture, email, first_name, last_name"}]
     startWithCompletionHandler:^(FBSDKGraphRequestConnection *connection, id result, NSError *error) {
         if (!error) {
             NSString *pictureURL = [NSString stringWithFormat:@"%@",[result objectForKey:@"picture"]];
             
             NSLog(@"First Name is %@", [result objectForKey:@"first_name"]);
             NSLog(@"Last Name is %@", [result objectForKey:@"last_name"]);
             NSLog(@"email is %@", [result objectForKey:@"email"]);
             NSLog(@"ProfilePic is %@", pictureURL);
             
             [self getFirebaseFacebookAuthentication];
             
         }
         else{
             NSLog(@"%@", [error localizedDescription]);
         }
     }];
}
    
-(void)getFirebaseFacebookAuthentication{
    FIRAuthCredential *credential = [FIRFacebookAuthProvider
                                     credentialWithAccessToken:[FBSDKAccessToken currentAccessToken].tokenString];
    [[FIRAuth auth] signInAndRetrieveDataWithCredential:credential
                                             completion:^(FIRAuthDataResult * _Nullable authResult,
                                                          NSError * _Nullable error) {
                                                 if (error) {
                                                     NSLog(@"%@",error);
                                                     TSTAlertView *alert = [[TSTAlertView alloc] init];
                                                     alert.backgroundType = Blur;
                                                     alert.showAnimationType = SlideInFromTop;
                                                     [alert showSuccess:self title:ALERT_TITLE subTitle:error.localizedDescription closeButtonTitle:nil duration:0.0f];
                                                     [alert addButton:@"Okay" actionBlock:^{
                                                         
                                                     }];
                                                     return;
                                                 }
    // User successfully signed in. Get user data from the FIRUser object
                                                 if (authResult == nil) { return; }
                                                 FIRUser *user = authResult.user;
                                                 
                                                 NSLog(@"%@", user.displayName);
                                                 NSLog(@"%@", user.email);
                                                 NSLog(@"%@", user.photoURL);
                                                 TSTAlertView *alert = [[TSTAlertView alloc] init];
                                                 alert.backgroundType = Blur;
                                                 alert.showAnimationType = SlideInFromTop;
                                                 [alert showSuccess:self title:ALERT_TITLE subTitle:@"Login Successfully." closeButtonTitle:nil duration:0.0f];
                                                 [alert addButton:@"Okay" actionBlock:^{
                                                     
                                                 }];
                                                 
    }];
}

#pragma mark - Google Login Method
- (void)signIn:(GIDSignIn *)signIn presentViewController:(UIViewController *)viewController
{
    [self presentViewController:viewController animated:YES completion:nil];
}

- (void)signIn:(GIDSignIn *)signIn dismissViewController:(UIViewController *)viewController {
    [self dismissViewControllerAnimated:YES completion:nil];
    
}
- (BOOL)application:(nonnull UIApplication *)application
            openURL:(nonnull NSURL *)url
            options:(nonnull NSDictionary<NSString *, id> *)options {
    return [[GIDSignIn sharedInstance] handleURL:url
                               sourceApplication:options[UIApplicationOpenURLOptionsSourceApplicationKey]
                                      annotation:options[UIApplicationOpenURLOptionsAnnotationKey]];
}

- (void)signIn:(GIDSignIn *)signIn didSignInForUser:(GIDGoogleUser *)user withError:(NSError *)error {
    // ...
    if (error == nil) {
        GIDAuthentication *authentication = user.authentication;
        FIRAuthCredential *credential =
        [FIRGoogleAuthProvider credentialWithIDToken:authentication.idToken
                                         accessToken:authentication.accessToken];
        
        [[FIRAuth auth] signInAndRetrieveDataWithCredential:credential
                                                 completion:^(FIRAuthDataResult * _Nullable authResult,
                                                              NSError * _Nullable error) {
                                                     if (error) {
                                                         NSLog(@"%@",error);
                                                         TSTAlertView *alert = [[TSTAlertView alloc] init];
                                                         alert.backgroundType = Blur;
                                                         alert.showAnimationType = SlideInFromTop;
                                                         [alert showSuccess:self title:ALERT_TITLE subTitle:error.localizedDescription closeButtonTitle:nil duration:0.0f];
                                                         [alert addButton:@"Okay" actionBlock:^{
                                                             
                                                         }];
                                                         
                                                         return;
                                                     }
                                                     // User successfully signed in. Get user data from the FIRUser object
                                                     if (authResult == nil) { return; }
                                                     FIRUser *user = authResult.user;
                                                     
                                                     NSLog(@"Name: %@",user.displayName);
                                                     NSLog(@"Email: %@",user.email);
                                                     
                                                     TSTAlertView *alert = [[TSTAlertView alloc] init];
                                                     alert.backgroundType = Blur;
                                                     alert.showAnimationType = SlideInFromTop;
                                                     [alert showSuccess:self title:ALERT_TITLE subTitle:@"Login Successfully." closeButtonTitle:nil duration:0.0f];
                                                     [alert addButton:@"Okay" actionBlock:^{
                                                         
                                                     }];
    }];
    } else {
        NSLog(@"%@",error);
    }
}


#pragma mark - Keyboard Notifications Methods
- (void) keyboardDidShow:(NSNotification *)notification{
    NSDictionary* info = [notification userInfo];
    CGRect kbRect = [[info objectForKey:UIKeyboardFrameBeginUserInfoKey] CGRectValue];
    kbRect = [self.view convertRect:kbRect fromView:nil];
    
    UIEdgeInsets contentInsets = UIEdgeInsetsMake(0.0, 0.0, kbRect.size.height, 0.0);
    self.scrollView.contentInset = contentInsets;
    self.scrollView.scrollIndicatorInsets = contentInsets;
    
    CGRect aRect = self.view.frame;
    aRect.size.height -= kbRect.size.height+60;
    if (!CGRectContainsPoint(aRect, self.txtFieldCheck.frame.origin) ) {
        [self.scrollView scrollRectToVisible:self.txtFieldCheck.frame animated:YES];
    }
}

- (void) keyboardWillBeHidden:(NSNotification *)notification
{
    UIEdgeInsets contentInsets = UIEdgeInsetsZero;
    self.scrollView.contentInset = contentInsets;
    self.scrollView.scrollIndicatorInsets = contentInsets;
}

- (UIView*)viewFormatingFunction:(UIView*)view
{
    CALayer *viewLayer = [view layer];
    [viewLayer setMasksToBounds:NO ];
    [viewLayer setShadowColor:[[UIColor lightGrayColor] CGColor]];
    [viewLayer setShadowOpacity:0.8 ];
    [viewLayer setShadowRadius:3.0 ];
    [viewLayer setShadowOffset:CGSizeMake( 0 , 0 )];
    [viewLayer setShouldRasterize:YES];
    [viewLayer setCornerRadius:3.0];
    
    [viewLayer setShadowPath:[UIBezierPath bezierPathWithRect:viewLayer.bounds].CGPath];
    return view;
}

-(void)showAlertWithTitle:(NSString*)Title WithMsg:(NSString*)Message {
    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:Title message: Message
                                                                      preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction *actionOk = [UIAlertAction actionWithTitle:@"Ok" style:UIAlertActionStyleDefault handler:nil];
    [alertController addAction:actionOk];
    [self presentViewController:alertController animated:YES completion:nil];
}
@end
