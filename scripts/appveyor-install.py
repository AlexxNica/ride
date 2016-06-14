#!/usr/bin/python
import urllib
import os
import zipfile

# todo: change wx solution to use static crt...
# sln file:
# Project("{8BC9CEB8-8B4A-11D0-8D11-00A0C91BC942}") = "richtext", "wx_richtext.vcxproj", "{7FB0902D-8579-5DCE-B883-DAF66A885005}"
# in vcxproj file: change:
# <RuntimeLibrary>MultiThreadedDebugDLL</RuntimeLibrary> to <RuntimeLibrary>MultiThreadedDebug</RuntimeLibrary>
# <RuntimeLibrary>MultiThreadedDLL</RuntimeLibrary> to <RuntimeLibrary>MultiThreaded</RuntimeLibrary>

platform='x64'
if os.environ['PLATFORM'] == 'x86':
  platform='Win32'

root = os.getcwd()
build = os.path.join(root, 'build')
wxbuild = os.path.join(build, 'wx')
localwxzip = os.path.join(build, "wx.zip")
wxsln = os.path.join(wxbuild, 'build', 'msw', 'wx_vc14.sln')
wxmsbuildcmd = 'msbuild /p:Configuration=Release /p:Platform="{platform}" {solution}'.format(platform=platform, solution=wxsln)

print root
print wxsln

os.makedirs(build)
os.makedirs(wxbuild)

wxurl = "https://github.com/wxWidgets/wxWidgets/releases/download/v3.1.0/wxWidgets-3.1.0.zip"

urllib.urlretrieve (wxurl, os.path.join(build, localwxzip))

with zipfile.ZipFile(localwxzip, 'r') as z:
    z.extractall(wxbuild)

os.system(wxmsbuildcmd)
