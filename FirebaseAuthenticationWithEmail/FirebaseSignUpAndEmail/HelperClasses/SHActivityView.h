//
//  ActivityView.h
//  CustomWaitHUD
//
//  Created by $heb!n Koshy on 2/18/16.
//  Copyright © 2016 $heb!n Koshy. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum SpinnerSize
{
    kSHSpinnerSizeTiny, // suitable for frmae size (30, 30)
    kSHSpinnerSizeSmall, // suitable for frame size (50, 50)
    kSHSpinnerSizeMedium, // suitable for frame size (150, 150)
    kSHSpinnerSizeLarge, // suitable for frame size (185, 185)
    kSHSpinnerSizeVeryLarge // suitable for frame size (220,220)
}SHSizes;




/**
 * a view that contain spinner on its center
 * use only programmatically
 * default background color = [UIColor colorWithWhite:0.2f alpha:0.5f], it wil not work when spinnerStyle = kSHSpinnerSizeSmall || kSHSpinnerSizeTiny
 * if you need to CHANGE the POSITION of the spinner you have to change it only after, -(void)showAndStartAnimate invoked
 */
@interface SHActivityView : UIView





/**
 * radius of the spinner/rotator will be different in each Spinner Size
 * default = kAVSpinnerSizeTiny
 * if its kSHSpinnerSizeVeryLarge or kSHSpinnerSizeLarge, kSHSpinnerSizeMedium, can able to set two title, one title in center of spinner and another in below the spinner
 */
@property(nonatomic,assign)SHSizes spinnerSize;




/**
 * spinner color
 * defaule = [UIColor whiteColor]
 */
@property(nonatomic,strong)UIColor *spinnerColor;






/**
 * disable the user interaction of entire application
 * default = NO
 */
@property(nonatomic,assign)BOOL disableEntireUserInteraction;





/**
 * center title
 * default = nil
 * WARNING, it wil not work when spinnerSize = kSHSpinnerSizeSmall || kSHSpinnerSizeTiny
 */
@property(nonatomic,strong)NSString *centerTitle;




/**
 * bottom title
 * default = nil
 * WARNING, it wil not work when spinnerSize = kSHSpinnerSizeSmall || kSHSpinnerSizeTiny
 */
@property(nonatomic,strong)NSString *bottomTitle;






/**
 * center title color
 * default = [UIColor whiteColor]
 * WARNING, it wil not work when spinnerSize = kSHSpinnerSizeSmall || kSHSpinnerSizeTiny
 */
@property(nonatomic,strong)UIColor *centerTitleColor;




/**
 * bottom title color
 * default = [UIColor whiteColor]
 * WARNING, it wil not work when spinnerSize = kSHSpinnerSizeSmall || kSHSpinnerSizeTiny
 */
@property(nonatomic,strong)UIColor *bottomTitleColor;




/**
 * center title font
 * WARNING, it wil not work when spinnerSize = kSHSpinnerSizeSmall || kSHSpinnerSizeTiny
 */
@property(nonatomic,strong)UIFont *centerTitleFont;





/**
 * bottom title font
 * WARNING, it wil not work when spinnerSize = kSHSpinnerSizeSmall || kSHSpinnerSizeTiny
 */
@property(nonatomic,strong)UIFont *bottomTitleFont;




/**
 * stop the three dot animation
 * WARNING, it wil not work when spinnerSize = kSHSpinnerSizeSmall || kSHSpinnerSizeTiny
 */
@property(nonatomic,assign)BOOL stopBottomTitleDotAnimation;





/**
 * stop animation when showing and dismissing the spinner
 */
@property(nonatomic,assign)BOOL stopShowingAndDismissingAnimation;





/**
 * to show the spinner and start its animation
 */
-(void)showAndStartAnimate;





/**
 * spinner will be removed
 */
-(void)dismissAndStopAnimation;


@end
