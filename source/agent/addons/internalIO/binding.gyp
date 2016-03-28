{
  'targets': [{
    'target_name': 'internalIO',
    'sources': [ 'addon.cc',
                 'InternalInWrapper.cc',
                 'InternalOutWrapper.cc' ],
    'include_dirs': [ '$(CORE_HOME)/common',
                      '$(CORE_HOME)/woogeen_base'],
    'libraries': ['-L$(CORE_HOME)/build/woogeen_base', '-lwoogeen_base'],
    'conditions': [
      [ 'OS=="mac"', {
        'xcode_settings': {
          'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',        # -fno-exceptions
          'GCC_ENABLE_CPP_RTTI':       'YES',        # -fno-rtti
          'MACOSX_DEPLOYMENT_TARGET':  '10.7',       # from MAC OS 10.7
          'OTHER_CFLAGS': ['-g -O$(OPTIMIZATION_LEVEL) -stdlib=libc++']
        },
      }, { # OS!="mac"
        'cflags!':    ['-fno-exceptions'],
        'cflags_cc':  ['-Wall', '-O$(OPTIMIZATION_LEVEL)', '-g' , '-std=c++11', '-frtti'],
        'cflags_cc!': ['-fno-exceptions']
      }],
    ]
  }]
}
