%global	commit f984731d36aef24e630ead0e3818efd3b0b99f07
%global shortcommit %(c=%{commit}; echo ${c:0:7})
Name:		brd
Version:	1.0
Release:	2%{?dist}
Summary:	Scans directories and files for damage due to decay of storage medium

License:	GPLv2+
URL:		https://github.com/jsbackus/brd
Source0:	https://github.com/jsbackus/brd/archive/%{commit}/%{name}-%{commit}.tar.gz

BuildRequires:	python3-devel
BuildArch:	noarch

%description
bit_rot_detector, or brd, is a tool to scan a directory tree and check each file
for corruption caused by damage to the physical storage medium or by damage from
malicious programs. Files are fingerprinted using the SHA-1 algorithm. File
fingerprints, sizes, and modification times are stored in a SQLite database.

%prep
%setup -qn %{name}-%{commit}

%build
%{__python3} setup.py build

%check
cd unit_tests
%{__python3} -m unittest

%install
%{__python3} setup.py install --skip-build --root $RPM_BUILD_ROOT

# Move docs to appropriate place for versions prior to Fedora 20.
%if 0%{?fedora} < 20
mv %{buildroot}/%{_datadir}/doc/%{name} %{buildroot}/%{_pkgdocdir}
%endif

%files
%doc LICENSE README
%{_bindir}/brd
%{_mandir}/man1/%{name}.1*
%{python3_sitelib}/%{name}*.egg-info


%changelog
* Tue Jul 01 2014 Jeff Backus <jeff.backus@gmail.com> - 1.0-2
- Modified to properly install docs on F19 and earlier.

* Sun Jun 15 2014 Jeff Backus <jeff.backus@gmail.com> - 1.0-1
- Initial package
