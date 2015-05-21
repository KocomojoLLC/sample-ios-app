Pod::Spec.new do |s|
    s.name = 'KocomojoSDK'
    s.version = '0.1.0'
    s.license = 'Commercial'
    s.summary = 'Proximity-based marketing service'
    s.homepage = 'http://admin.kocomojo.net/'
    s.author = 'Kocomojo'
    s.source = { :http => "https://dl.dropboxusercontent.com/u/1478671/KocomojoSDK.framework.zip" }
    s.platform = :ios
    # s.source_files = "Chartboost.framework/Versions/A/Headers/*.h",
    # "preserve_paths": "Chartboost.framework/*",
    s.source_files = '**/*.h'
    s.preserve_paths = 'KocomojoSDK.framework'
    s.vendored_frameworks = 'KocomojoSDK.framework'
    # s.library = 'KocomojoSDK'
    # s.xcconfig = { 'LIBRARY_SEARCH_PATHS' => '"$(PODS_ROOT)/KocomojoSDK/KocomojoSDK"' }
    s.dependency "CocoaLumberjack", "2.0.0-rc2"
    s.dependency "AFNetworking", "~> 2.0"
    s.frameworks = 'CoreLocation'
end