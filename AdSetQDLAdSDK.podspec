Pod::Spec.new do |s|
  s.name = 'AdSetQDLAdSDK'
  s.version = '1.9.5.1'
  s.summary = '趣盟 L 渠道 iOS 广告 SDK 二进制包'
  s.description = '趣盟 AdSetQDLAdSDK 1.9.5.1 的 XCFramework 分发包，包含 iOS 框架、随附广告资源及隐私清单。'
  s.homepage = 'https://github.com/OSETSDK/AdSetQDLAdSDK'
  s.license = {
    :type => 'MIT',
    :text => 'MIT is the license type declared in the publisher-supplied podspec. See NOTICE for the publisher attribution and the delivery package license information.'
  }
  s.author = { 'chenxin02' => 'chenxin02@qutoutiao.net' }
  s.source = {
    :git => 'https://github.com/OSETSDK/AdSetQDLAdSDK.git',
    :tag => s.version.to_s
  }

  s.ios.deployment_target = '11.0'
  s.swift_version = '5.1'
  s.vendored_frameworks = 'AdSetQDLAdSDK.xcframework'
  s.frameworks = 'UIKit', 'CoreLocation', 'SystemConfiguration', 'CoreGraphics',
                 'CoreMotion', 'CoreTelephony', 'AdSupport', 'QuartzCore',
                 'WebKit', 'MessageUI', 'SafariServices', 'AVFoundation',
                 'EventKit', 'CoreMedia', 'StoreKit', 'Accelerate', 'CFNetwork',
                 'CoreFoundation', 'Foundation', 'ImageIO', 'JavaScriptCore',
                 'LocalAuthentication', 'MobileCoreServices', 'Security'
  s.weak_frameworks = 'DeviceCheck'
  s.libraries = 'sqlite3', 'z'
  s.static_framework = true
  s.resources = ['AdSetQDLAdBundle.bundle', 'AdSetQDLAdSDKPrivacy.bundle']

  s.xcconfig = { 'ENABLE_BITCODE' => 'NO', 'OTHER_LDFLAGS' => '-ObjC' }
  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
end
