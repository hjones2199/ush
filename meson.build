project('ush', ['cpp'],
  version : '0.72',
  default_options : ['warning_level=3',
                     'cpp_std=c++17',
                     'cpp_args=-pedantic -O2 -pipe -D_FORTIFY_SOURCE=2 -D_GLIBCXX_ASSERTIONS -fstack-clash-protection -Werror=unused-variable'])

editline_dep = dependency('libedit', version : '>=3.1', required : true)

exe = executable('ush', 'src/ush.cpp', install : true, dependencies : editline_dep)

