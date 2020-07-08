//
//  FMLayoutView.h
//  FMLayoutKit
//
//  Created by 周发明 on 2020/4/1.
//  Copyright © 2020 ZhouFaMing. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FMLayout.h"

NS_ASSUME_NONNULL_BEGIN
@class FMLayoutView;
@protocol FMCollectionLayoutViewConfigurationDelegate <NSObject>
@optional
- (void)layoutView:(FMLayoutView *)layoutView configurationCell:(UICollectionViewCell *)cell indexPath:(NSIndexPath *)indexPath;
- (void)layoutView:(FMLayoutView *)layoutView configurationHeader:(UICollectionReusableView *)header indexPath:(NSIndexPath *)indexPath;
- (void)layoutView:(FMLayoutView *)layoutView configurationFooter:(UICollectionReusableView *)footer indexPath:(NSIndexPath *)indexPath;
- (void)layoutView:(FMLayoutView *)layoutView configurationSectionBg:(UICollectionReusableView *)bg indexPath:(NSIndexPath *)indexPath;
@end

@interface FMLayoutView : UICollectionView
@property(nonatomic, weak)id<FMCollectionLayoutViewConfigurationDelegate> configuration;
@property(nonatomic, weak)FMLayout *layout;
@property(nonatomic, assign)BOOL reloadOlnyChanged;
- (instancetype)initWithFrame:(CGRect)frame collectionViewLayout:(UICollectionViewLayout *)layout NS_UNAVAILABLE;
- (instancetype)initHorizontal;
- (instancetype)initHorizontalWithFrame:(CGRect)frame;
/// 添加插入数组
- (void)appendLayoutSections:(NSArray<FMLayoutBaseSection *> *)sections;
- (void)insertLayoutSections:(NSArray<FMLayoutBaseSection *> *)sections atIndexSet:(NSIndexSet *)indexSet;
- (void)insertLayoutSection:(FMLayoutBaseSection *)section atIndex:(NSInteger)index;

/// 删除分组
- (void)deleteLayoutSections:(NSArray<FMLayoutBaseSection *> *)sections;
- (void)deleteLayoutSectionAt:(NSUInteger)index;
- (void)deleteLayoutSectionSet:(NSIndexSet *)set;

/// 交换分组
- (void)exchangeLayoutSection:(NSUInteger)index to:(NSUInteger)to;

- (void)reloadChangedSectionsData;

@end

NS_ASSUME_NONNULL_END