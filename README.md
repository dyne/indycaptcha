# indyCaptcha

Emancipate yourselves from CAPTCHA slavery,

None but ourselves can free our web services!

<img src="http://www.startmotionmedia.com/wp-content/uploads/2012/09/Adam-Scott-Miller_HoldingSpace_8.5x11.jpg">

Today is your day to let go of things that no longer serve you.

## Introduction

indyCaptcha is a minimal and independent C99 implementation of a
[CAPTCHA](https://en.wikipedia.org/wiki/CAPTCHA) generator using
configurable fonts and list of words. This software is a response to
the growing adoption of Google's reCaptcha and its annoying usage to
mock humans to prove they are not AI by training other AIs.

## History

indyCaptcha was originally made in 2013 as an off-line and non-spying
implementation to be used in the subscription mechanism of the
[Italian Pirate Party](https://partito-pirata.it), subsequently
published as a stand-alone portable software in 2018 following the
inspiration given by [reading James Swineson's comments on
reCaptcha](https://twitter.com/zhjits/status/1053997145307734016).

Further motivation to the development and adoption of this software
can be found in the [Algorithmic Sovereignty](https://algosov.org)
discourse.

## Tech details

indyCaptcha only dependency is from
[libGD2](https://libgd.github.io/), the aim is that of making it
portable and embeddable into any platform (MS/Win, Apple/OSx,
GNU/Linux, Android, iOS, nodeJS, WASM) and compilable as a fully
static and isolated software that can be deployed on-chip (unikernel).

## Acknowledgements

indyCaptcha is Copyright (C) 2013-2018 by Dyne.org foundation

Designed, written and maintained by Denis Roio <jaromil@dyne.org>

Upcoming contributions will be listed here.
      
Permission is granted to copy, distribute and modify indyCaptcha in
any context without fee, including a commercial application, provided
that this notice is present in user-accessible supporting
documentation.

This does not affect your ownership of the derived work itself, and
the intent is to assure proper credit for the authors of indyCaptcha,
not to interfere with your productive use of indyCaptcha.  "Derived
works" includes all programs that utilize indyCaptcha library. Credit
must be given in user-accessible documentation.

This software is provided "AS IS." The copyright holders disclaim
all warranties, either express or implied, including but not
limited to implied warranties of merchantability and fitness for a
particular purpose, with respect to this code and accompanying
documentation.

If you have questions, ask.  This license is in fact Apache 2.0
license reported below and in the LICENSE.txt file included in all
distributions of indyCaptcha.

```
   Copyright 2013-2018 Dyne.org foundation, Amsterdam

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License. 
```
