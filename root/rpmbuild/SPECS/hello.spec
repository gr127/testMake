Name:           hello
Version:        1.0
Release:        1%{?dist}
Summary:        Prints Hello RTSoft

License:        GPL
URL:            none
Source0:        hello-1.0.tar.gz

BuildRequires:  gcc 
Requires:       glibc

%description
Outputs HelloRTSoft. We love this company.

%prep
%setup -q


%build
make

%install
mkdir -p $RPM_BUILD_ROOT/usr/bin/
install -p -m  777 hello $RPM_BUILD_ROOT/usr/bin/


%files
%config %attr(0777,root,root) /usr/bin/hello



%changelog
* Fri Jul 10 2015 Andrey Rusalin <rt_practiv@dev.rtsoft.ru> - 1.0.1
- initial release
- 
