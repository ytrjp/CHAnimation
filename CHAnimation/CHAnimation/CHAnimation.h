//
//  CHAnimation.h
//  CHAnimation
//
//  Created by hangchen on 5/20/14.
//  Copyright (c) 2014 Hang Chen (https://github.com/cyndibaby905)
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.

#import <Foundation/Foundation.h>
@class CHAnimationState;

@interface CHAnimation : NSObject

@property (nonatomic, assign)id obj;
@property (copy, nonatomic) NSString *name;
@property (assign, nonatomic) CFTimeInterval beginTime;
@property (assign, nonatomic) CFTimeInterval duration;
@property (copy, nonatomic) id fromValue;
@property (copy, nonatomic) id toValue;
@property (readwrite, nonatomic, copy) id (^readBlock)(id obj);
@property (readwrite, nonatomic, copy) void (^writeBlock)(id obj, id value);
@property (readwrite, nonatomic, copy) id (^progressBlock)(id obj, CGFloat progress);


@end

CHAnimationState *CHAnimationGetState(CHAnimation *a);

@interface NSObject (CHAnimation)


- (void)ch_addAnimation:(CHAnimation *)anim forKey:(NSString *)key;


- (void)ch_removeAllAnimations;


- (void)ch_removeAnimationForKey:(NSString *)key;


@end
