# AdSetQDLAdSDK

趣盟 L 渠道 iOS 广告 SDK 二进制分发包，版本为 `1.9.4.6`。CocoaPods 交付规格指向本仓库同名 Git tag。

```ruby
pod 'AdSetQDLAdSDK', '1.9.4.6'
```

交付的动态 XCFramework 包含内嵌资源和隐私清单。真机切片支持 arm64，最低系统版本为 iOS 11.0。模拟器包含 x86_64 和 arm64 切片，后者的二进制最低系统版本为 iOS 14.0。podspec 沿用原厂配置，排除模拟器 arm64，CocoaPods 集成使用 x86_64 模拟器构建。

原始附件 `AdSetQDLAdSDK.zip` 的 SHA-256 为 `259d0f2c174a710743a074517fd29bad7e84763446e034aec917e5e38241f57c`。交付使用附件外层的 XCFramework。原厂署名和许可信息见 [NOTICE](NOTICE)。
