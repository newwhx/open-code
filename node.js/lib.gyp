{
    'targets': [
      {
        'target_name': 'foo', #项目名称
        'type': '<(library)'  # 支持 executable, static_library, shared_library 和none
        'msvs_guid': '5ECEC9E5-8F23-47B6-93E0-C3B328B3BE65', #生成vs工程的时候使用
        'dependencies': [ #这里面包含的是本target依赖的其他的targets
          'xyzzy',
          '../bar/bar.gyp:bar',
        ],
        'defines': [ #预处理宏 类似命令行中的-D 或者/D 选项
          'DEFINE_FOO',
          'DEFINE_A_VALUE=value',
        ],
        'include_dirs': [ #包含的头文件的查找目录 类似命令行中-I或者/I选项
          '..',
        ],
        'direct_dependent_settings': { # 提供给其他依赖本target的target的设置
          'defines': [
            'DEFINE_FOO',
            'DEFINE_ADDITIONAL',
          ],
          'linkflags': [
          ],
        },
        'export_dependent_settings': [ # target之间相互依赖的设置
          '../bar/bar.gyp:bar',
        ],
        'sources': [ #包含的是需要编译的源文件
          'file1.cc',
          'file2.cc',
        ],
				'cflags': ['-Werror', ] # 增加编译选项
				'ldflags': ['-pthread', ] # 增加链接选项
				'link_settings': '' #指定target需要链接的库. executable和shared_library类型的target需要指定链接库.;
        'conditions': [ #定义不同平台的编译特性
          ['OS=="linux"', {
            'defines': [
              'LINUX_DEFINE',
            ],
            'include_dirs': [
              'include/linux',
            ],
          ],
          ['OS=="win"', {
            'defines': [
              'WINDOWS_SPECIFIC_DEFINE',
            ],
          }, { # OS != "win",
            'defines': [
              'NON_WINDOWS_DEFINE',
            ],
          }]
        ],
    ],
  }
