# AutoEntitle
Automatically entitle, sign, fix permissions &amp; unstash binaries and apps installed via Cydia on iOS 11
Criticism is welcome as long as you tell me where the issue stays so I can fix. Yes, I'm replacing the dpkg binary with a patched one, there is no better way I can think of, to entitle a postinst before installation. Already tried code-injection to Cydia's system() but had a lot of issues. Don't worry, I've taken care when a user reinstalls dpkg (or updates it), I'm using a triggered postinst to install this again. Hopefully I've not missed any bug.
