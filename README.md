# AdSetQDLAdSDK

趣盟 L 渠道 iOS 广告 SDK 二进制分发包，版本为 `1.9.5.1`。CocoaPods 交付规格指向本仓库同名 Git tag。

```ruby
pod 'AdSetQDLAdSDK', '1.9.5.1'
```

交付包含静态 XCFramework、广告资源包 `AdSetQDLAdBundle.bundle` 和隐私资源包 `AdSetQDLAdSDKPrivacy.bundle`。真机切片支持 arm64，最低系统版本为 iOS 11.0。模拟器包含 x86_64 和 arm64 切片，Podspec 沿用厂商配置排除模拟器 arm64，CocoaPods 集成使用 x86_64 模拟器构建。

原始附件 `AdSetQDLAdSDK(1).zip` 的 SHA-256 为 `54846b984d75fb414fdff9043ce1d3ace480966f7026bd5f76fa6046b1b09e57`。交付使用附件 `Demo/AdSetQDLAdSDK` 下的 XCFramework 和两个资源包。厂商署名和许可信息见 [NOTICE](NOTICE)。
