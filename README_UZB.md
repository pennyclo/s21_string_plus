# s21_string+

string.h kutubxonasini qo'shimchalar bilan amalga oshirish.

💡 [Ushbu loyiha](https://new.oprosso.net/p/4cb31ec3f47a4596bc758ea1861fb624), **haqida biz bilan fikr-mulohazalaringizni baham ko’rish uchun bu yerni bosing**. Bu anonim bo’lib, jamoamizga ta’limni yaxshilashga yordam beradi. Loyihani tugatgandan so'ng darhol so'rovnomani to'ldirishni tavsiya qilamiz.

## Contents
0. [Preamble](#preamble)
1. [Chapter I](#chapter-i) \
    1.1. [Introduction](#introduction) 
2. [Chapter II](#chapter-ii) \
    2.1. [Information](#information)
3. [Chapter III](#chapter-iii) \
    3.1. [Part 1.](#part-1--stringh-kutubxonasi-funksiyalarini-amalga-oshirish) \
    3.2. [Part 2.](#part-2-sprintf-funksiyasini-qisman-amalga-oshirish) \
    3.3. [Part 3.](#part-3-qoshimcha-bazi-sprintf-funksiyasi-formati-modifikatorlarini-amalga-oshirish) \
    3.4. [Part 4.](#part-4-qoshimcha-sscanf-funksiyasini-amalga-oshirish) \
    3.5. [Part 5.](#part-5-дополнительно-реализация-специальных-функций-обработки-строк)

## Preamble

![s21_string+](misc/rus/images/s21_stringplus.png)

1942-yil, kech oqshom, Bletchli Park, Alan Tyuringning ish stoli.

Deyarli bir yil davomida bir guruh eng aqlli matematiklar, tilshunoslar va krossvord ishqibozlari juda qiyin muammoni hal qilishga – kodlari har kuni o'zgarib turadigan nemis “Enigma” shifrlash mashinasini shifrlashga harakat qilmoqdalar, mumkin bo'lgan kombinatsiyalar soni esa taxminan 64-darajada 2 ga teng. Bu guruh ko'pincha turli xil algoritmlarni o'ylab topishiga to'g'ri keldi hamda fikr almashinish va bayonnomalar yuritish qulayligi uchun koinotimizda dong taratgan C tiliga ikki tomchi suvdek o'xshash maxsus kalit so'zlar to'plami va ulardan foydalanish sintaksisi ishlab chiqildi. Bir-biriga to’g’ri kelishi mumkin-ku! Bletchli Park xodimlari uchun yagona noqulaylik – bu tilda tasvirlangan barcha harakatlar ketma-ketligini boshlarida saqlashlariga to’g’ri kelardi.

Tyuring stoli yonidan o‘tayotganda, “Harflar, tinish belgilari, so‘z va jumlalarni qayta ishlash uchun” deb yozilgan qog‘ozga ko‘zingiz tushadi.

*— Bu nima, Alan? —* deraza yonidagi o‘ychan yigitga yuzlandingiz.

*— Bu bizning hayotimizni soddalashtiradigan funksiyalar! O’zing bilasanku, Enigmani xomaki tartibga solish usuli yordamida rasshifrovkalash... Men buni hal qilishdan ko'ra tezroq Joanga uylanardim. Shuning uchun, menimcha, biz matnlarni tahlil qilishda davom etishimiz, qonuniyatlar va o’xshashliklarni izlashimiz kerak. Buning uchun esa aynan shu matnni qayta ishlash bilan bog'liq turli xil algoritmlarni o’ylab topish va tavsiflash kerak bo'ladi. Shuning uchun* *bizga buni amalga oshirishga yordam beradigan bir qator funksiyalar kerak. Hozir shularni o'ylab topishga harakat qilyapman.*

*— Algoritmlarni tavsiflash uchun yangi yagona vositamizga o'ylab topyapsanmi?*

*— Ha, aynan o’shanga. Bu funksiyalar yana qayerda ham bizga asqatadi?* – shunday deya, Tyuring sizga ahmoqqa qaragandek qaradi. Buni tushunib, siz ushbu masalada o'z bilimingizni ko'rsatishga qaror qildingiz:

*— Bilasanmi, menimcha, bu bizga haqiqatdan ham kerak. Men o’zi buni yaqinda bilib oldim, buni algoritmlarni uzatish uchun maxsus til deb ataymiz.*

*—  Rostdanmi?* – biroz qiziqish bilan so‘radi Alan.

*— Ha, ha.*

Bir necha soniya o'ylab, Tyuring bu ishni sizga ishonib topshirish mantiqan to'g'ri, degan qarorga keldi:

*— Menga qara, bu bilan o'zing shug’ullanishni xohlamaysanmi? Bir nechta bekor odamlarni tanlab, davom et. Men esa kodlarni tartibga solish uchun mexanik mashinam ustida ishlashni davom ettiraman.*

Bir necha soniya o'ylab, siz, bu ajoyib g'oya degan fikrga keldingiz:

*-Ha, men hammasini zo’r qilaman!*


## Chapter I

## Introduction

Ushbu loyihada siz C dasturlash tilida string.h kutubxonasini ba'zi qo'shimchalar bilan (sprintf va sscanf funksiyalarini shaxsan amalga oshirish bilan) shaxsan amalga oshirish ustida ishlaysiz. string.h kutubxonasi satrlarni qayta ishlash bo’yicha asosiy C tili kutubxonasidir. Ushbu loyiha doirasida siz satr ma'lumotlari bilan o'zaro ishlash ko'nikmalaringizni rivojlantirib, tizimli yondashuvingizni mustahkamlaysiz.

## Chapter II

## Information

C dasturlash tili o'zining standart kutubxonasida satrlar (belgili satrlar va bayt satrlari) bilan operatsiyalarni amalga oshiradigan funksiyalar to'plamini o'z ichiga oladi. U nusxa ko'chirish, konkatenatsiya, belgilash va qidirish kabi operatsiyalarni qo'llab-quvvatlaydi. Belgili satrlar uchun standart kutubxona qoidasi shundaki, satrlar nul tugatish belgisi bilan yakunlanishi kerak: n ta belgidan iborat satr n + 1 elementdan iborat massiv shaklida ifodalanadi, ularning oxirgisi "NULL" belgisi hisoblanadi.

Aslida, C dasturlash tilida satrlarni qo'llab-quvvatlaydigan yagona narsa, kompilyator ishorali satr konstantalarini nol bilan yakunlanuvchi satrlarga aylantirishidir.

### string.h Turlar

| № | Oʻzgaruvchi | Tavsif |
| ------ | ------ | ------ |
| 1 | size_t | sizeof kalit so'zidan kelib chiqqan belgisiz butun sonli tur.
	
### string.h Makroslar

| № | Makros | Tavsif |
| ------ | ------ | ------ |
| 1 | NULL | Nol ko'rsatkich konstantasining qiymati hisoblanuvchi makros.

### string.h Funksiya

| № | Funksiya | Tavsif |
| ------ | ------ | ------ |
| 1 | void *memchr(const void *str, int c, size_t n) | str argumenti bilan ko'rsatilgan satrning birinchi n baytida c belgisining (belgisiz turdagi) birinchi paydo bo'lishini qidiradi. |
| 2 | int memcmp(const void *str1, const void *str2, size_t n) | str1 va str2 ning birinchi n baytini solishtiradi. |
| 3 | void *memcpy(void *dest, const void *src, size_t n) | src dan dest ga n ta belgidan nusxa ko'chiradi. |
| 4 | void *memset(void *str, int c, size_t n) | c belgisini (belgisiz turdagi) str argumenti bilan ko'rsatilgan satrning birinchi n ta belgisiga ko'chiradi. |
| 5 | char *strncat(char *dest, const char *src, size_t n) | src bilan ko'rsatilgan qatorni dest bilan ko'rsatilgan qatorning oxiriga, uzunligi n ta belgigacha qo'shadi |
| 6	| char *strchr(const char *str, int c) | str argumenti bilan ko'rsatilgan satrda c belgisining (belgisiz turdagi) birinchi paydo bo'lishini qidiradi. |
| 7 | int strncmp(const char *str1, const char *str2, size_t n) | str1 va str2 ning ko'pi bilan birinchi n baytini solishtiradi. |
| 8 | char *strncpy(char *dest, const char *src, size_t n) | src tomonidan ko'rsatilgan satrdan dest ga n tagacha belgidan nusxa ko'chiradi. |
| 9 | size_t strcspn(const char *str1, const char *str2) | str2 ga kiritilmagan, butunlay belgilardan iborat bo’lgan str1 ning boshlang‘ich segmenti uzunligini hisoblab chiqadi. |
| 10 | char *strerror(int errnum) | errnum xato raqami uchun ichki massiv bo’yicha qidiradi va xato xabarini o'z ichiga olgan satrga ko'rsatkichni qaytaradi. Mac va Linux operatsion tizimlari uchun xato xabarlari massivlarini o'z ichiga olgan makroslarni e'lon qilish kerak. Xato tavsiflari asl kutubxonada mavjud. Joriy operatsion tizimni tekshirish direktivlar yordamida amalga oshiriladi. |
| 11 | size_t strlen(const char *str) | Tugatuvchi nol belgisini o'z ichiga olmasdan, str satr uzunligini hisoblaydi. |
| 12 | char *strpbrk(const char *str1, const char *str2) | str2 da ko‘rsatilgan har qanday belgiga mos keladigan str1 satrida birinchi belgini topadi. |
| 13 | char *strrchr(const char *str, int c) | str argumenti bilan ko'rsatilgan satrda c belgisining (belgisiz turdagi) oxirgi paydo bo’lishini izlaydi. |
| 14 | char *strstr(const char *haystack, const char *needle) | haystack satrida paydo boʻladigan butun needle satrining (yakunlovchu nol belgisini hisobga olmaganda) birinchi paydo bo’lishini topadi. |
| 15 | char *strtok(char *str, const char *delim) | str satrini delim bilan ajratilgan tokenlar qatoriga ajratadi. |

### sprintf and sscanf

- int sscanf(const char *str, const char *format, ...) — satrdan formatlangan kiritishni hisoblaydi.
- int sprintf(char *str, const char *format, ...) — Formatlangan chiqishni str bilan ko'rsatilgan satrga yuboradi.

bunda:
- str – bu funksiya ma'lumotlarni chiqarish uchun manba sifatida ishlaydigan C-satr;
- format – bu C satr bo'lib, quyidagi elementlardan birini yoki bir nechtasini o'z ichiga oladi: bo'sh joyli belgi, bo'sh joy bo'lmagan belgi va format spetsifikatorlari. Chop etish funksiyalari uchun format spetsifikatori quyidagi prototipga amal qiladi: %[bayroqlar][kenglik][.aniqlik][uzunlik]spetsifikator. Skanerlash funksiyalari uchun format spetsifikatori quyidagi prototipga amal qiladi: %[*][kenglik][uzunlik] spetsifikator.

### sprintf and sscanf Spetsifikatorlar

| № | Spetsifikator | sprintf natijasi | sscanf natijasi |
| --- | --- | --- | --- |
| 1 | c | Belgi | Belgi |
| 2 | d | Belgili o’nli butun son | Belgili o’nli butun son |
| 3 | i | Belgili o’nli butun son | elgili butun son (o'nli, sakkizli yoki o'n oltili bo'lishi mumkin) |
| 4 | e | e belgisidan foydalangan holda ilmiy notatsiya (mantissa/eksponent) (raqam chiqishi e-6 gacha aniqlikda mos kelishi kerak) | Suzuvchi nuqtali o’nli son yoki ilmiy notatsiya (mantissa/eksponent) |
| 5 | E | E belgisidan foydalangan holda ilmiy notatsiya (mantissa/eksponent). | Suzuvchi nuqtali o’nli son yoki ilmiy notatsiya (mantissa/eksponent) |
| 6 | f | Suzuvchi nuqtali o’nli son | Suzuvchi nuqtali o’nli son yoki ilmiy notatsiya (mantissa/eksponent) |
| 7 | g | Eng qisqa o’nli son ko'rinishdan foydalanadi | Suzuvchi nuqtali o’nli son yoki ilmiy notatsiya (mantissa/eksponent) |
| 8 | G | Eng qisqa o’nli son ko'rinishdan foydalanadi | Suzuvchi nuqtali o’nli son yoki ilmiy notatsiya (mantissa/eksponent) |
| 9 | o | Belgisiz sakkizli son | Belgisiz sakkizli son |
| 10 | s | Belgilar qatori | Belgilar qatori |
| 11 | u | Belgisiz o'nli butun son | Belgisiz o'nli butun son |
| 12 | x | Belgisiz o'n oltili butun son | Belgisiz o'n oltili butun son (har qanday harf) |
| 13 | X | Belgisiz o'n oltili butun son (katta harflar) | Belgisiz o'n oltili butun son (har qanday harf) |
| 14 | p | Ko’rsatkich manzil | Ko’rsatkich manzil |
| 15 | n | %n paydo bo'lishidan oldin chop etilgan belgilar soni | %n paydo bo'lishidan oldin hisoblangan belgilar soni |
| 16 | % | Belgi % | Belgi % |

### sprintf Bayroqlar

| № | Bayroq | Tavsif |
| --- | --- | --- |
| 1 | - | Belgilangan maydon kengligi chegarasida chap tomon bo’ylab tekislash. O'ng tomon bo’ylab tekislash asl sozlamalar bo'yicha ishlatiladi (kenglikning quyi spetsifikatoriga qarang). |
| 2 | + | Plyus yoki minus belgisini (+ yoki -) hatto musbat raqamlar uchun ham aniq ko'rsatishga majbur qiladi. Asl sozlamalar bo’yicha, faqat manfiy raqamlar oldida "-" belgisi mavjud. |
| 3 | (bo'sh joy) | Agar belgi chiqarilmasa, qiymatdan oldin bo'sh joy qo'yiladi. |
| 4 | # | о, x yoki X spetsifikatorlari bilan foydalanilganda, raqamdan oldin mos ravishda 0, 0x yoki 0X qo'yiladi (noldan boshqa qiymatlar uchun). e, E va f bilan foydalanilganda, undan keyin hech qanday raqam bo'lmasa ham, qayd etilgan chiqish o'nli nuqtani o'z ichiga olishga "majbur qiladi". Asl sozlamalar bo’yicha, agar undan keyin hech qanday raqam ketmasa, o’nli nuqta yozilmaydi. g yoki G bilan foydalanilganda, natija e yoki E bilan bir xil bo'ladi, lekin oxirgi nollar o'chirilmaydi. |
| 5 | 0 | Chapdagi raqamni kenglik spetsifikatori ko'rsatilgan bo'shliqlar o'rniga nollar (0) bilan to'ldiradi (kenglikning quyi spetsifikatoriga qarang). |

### sprintf and sscanf Kenglik

| № | Kenglik | Tavsif |
| --- | --- | --- |
| 1	| (son) | sprintf tomonidan chop etiluvchi belgilarning minimal soni. Agar chiqish qiymati bu raqamdan qisqaroq bo'lsa, natija bo'sh joylar bilan to'ldiriladi. Natija kattaroq bo'lsa ham, qiymat qisqartirilmaydi. sscanf uchun bu maydon uchun o'qiladigan belgilarning maksimal soni. |
| 2 | * | sprintf da * belgisi kenglik format satrida emas, balki formatlantirish lozim bo’lgan argument oldidagi butun son qiymatining qo'shimcha argumenti sifatida ko’rsatilishini bildiradi. sscanf da % dan keyin va format spetsifikatoridan oldin qo'yilgan * belgisi, ko’rsatilgan turdagi ma'lumotlarni hisoblaydi, lekin ularning o’zlashtirilishini bostiradi. |

### sprintf Aniqlik

| № | .точность | Tavsif |
| --- | --- | --- |
| 1	| .son | Butun son spetsifikatorlari uchun (d, i, o, u, x, X) – aniqlik yoziladigan raqamlarning minimal miqdorini aniqlaydi. Agar yoziluvchi qiymat bu raqamdan qisqaroq bo'lsa, natija ergashtiruvchi nollar bilan to'ldiriladi. Natija uzunroq bo'lsa ham, qiymat qisqartirilmaydi. 0 aniqligi 0 qiymati uchun hech qanday belgi yozilmasligini bildiradi. e, E va f spetsifikatorlari uchun – bu o’nli nuqtadan keyin chop etilishi kerak bo'lgan raqamlar soni. g va G spetsifikatorlari uchun – bu chop etilishi kerak bo'lgan ma’noli raqamlarning maksimal soni. s uchun – bu chop etiluvchi belgilarning maksimal soni. Asl sozlamalar bo’yicha, barcha belgilar yakunlovchi nolga duch kelmaguncha chop etiladi. c turi uchun u hech qanday ta'sir ko'rsatmaydi. Agar e, E, f, g va G spetsifikatorlari uchun aniqlik belgilanmagan bo'lsa, uning asl sozlamalar bo’yicha qiymati 6 bo'ladi. Qolgan spetsifikatorlar uchun aniqlik belgilanmagan bo'lsa, uning asl sozlamalar bo’yicha qiymati 1 bo'ladi. Agar son ko'rsatilmagan bo'lsa (aniq aniqlik qiymati yo'q), unda asl sozlamalar bo’yicha 0 bo'ladi. |
| 2	| .* | niqlik format satrida emas, balki formatlantirish lozim bo’lgan argument oldidagi butun son qiymatining qo'shimcha argumenti sifatida ko’rsatiladi. |

### sprintf and sscanf Uzunlik

| № | Uzunlik | Tavsif |
| --- | --- | --- |
| 1 | h | Argument qisqa int yoki belgisiz qisqa int sifatida talqin qilinadi (faqat butun sonli spetsifikatorlar uchun qo’llaniladi: i, d, o, u, x va X). |
| 2 | l | Argument butun sonli spetsifikatorlar (i, d, o, u, x va X) uchun uzun int yoki belgisiz uzun int sifatida va c va s spetsifikatorlari uchun keng belgi yoki keng belgilar satri sifatida talqin etiladi. |
| 3 | L | Argument uzun double sifatida talqin qilinadi (faqat e, E, f, g va G suzuvchi nuqtali spetsifikatorlar uchun qo’llaniladi). |

### Satrlarni qayta ishlashning maxsus funksiyalari (C# tilidagi String sinfidan ilhomlangan)

| № | Funksiya | Tavsif |
| ------ | ------ | ------ |
| 1 | void *to_upper(const char *str) | Baland registrga aylantirilgan satrning (str) nusxasini qaytaradi. Har qanday xato holatida, NULL qiymati qaytarilishi kerak. |
| 2 | void *to_lower(const char *str) | Kichik registrga aylantirilgan satr (str) nusxasini qaytaradi. Har qanday xato holatida, NULL qiymati qaytarilishi kerak. |
| 3 | void *insert(const char *src, const char *str, size_t start_index) | Berilgan satrda (src) ko’rsatilgan pozitsiyaga (start\_index) qo’yilgan ko’rsatilgan satr (str) bilan yangi qatorni qaytaradi. Har qanday xato holatida, NULL qiymati qaytarilishi kerak. |
| 4 | void *trim(const char *src, const char *trim_chars) | Berilgan satrdan (src) belgilangan belgilar to‘plamining (trim\_chars) barcha boshlang’ich va yakuniy kirishlarni olib tashlaydigan yangi qatorni qaytaradi. Har qanday xato holatida, NULL qiymati qaytarilishi kerak. |


## Chapter III

## Part 1.  string.h kutubxonasi funksiyalarini amalga oshirish

Yuqorida tavsiflangan string.h kutubxonasi funksiyalarini amalga oshirishingiz lozim, shuningdek, s21_size_t turini va S21_NULL makrosini amalga oshirish kerak:

- Kutubxona gcc kompilyatoridan foydalangan holda C11 standartidagi C tilida ishlab chiqilishi kerak.
- Kutubxona kodi, jumladan sarlavha fayllari, meyk fayllar va kutubxonaning o'zi develop tarmog’idagi src papkasida joylashgan bo'lishi kerak.
- Eskirgan yoki iste’moldan chiqarilgan til konstruksiyalari va kutubxona funksiyalaridan foydalanmang. Til va ishlatiluvchi kutubxonalar bo’yicha rasmiy hujjatlardagi legacy va obsolete belgilariga e'tibor bering. POSIX.1-2017 standartiga qarab mo’ljal oling.
- Kod yozishda Google Style ga amal qilinishi kerak.
- Yechimni s21\_string.a nomli statik kutubxona sifatida loyihalashtiring (s21\_string.h sarlavha fayli bilan).
- Kutubxona tuzilmaviy dasturlash tamoyillariga muvofiq ishlab chiqilishi kerak, koddagi takrorlanishlarni albatta bartaraf eting.
- Check kutubxonasidan foydalanib, kutubxona funksiyalarining to'liq unit testlar bilan qoplamasini tayyorlang.
- Unit testlar sizning realizatsiyangiz ish natijalarini string.h. standart kutubxonasi realizatsiyasi bilan solishtirish orqali tekshirishi kerak.
- Unit testlar har bir funksiyaning kamida 80% ini qamrab olishi kerak.
- Kutubxona va testlarni yig’ish uchun Makefile ni nazarda tuting (all, clean, test, s21\_string.a, gcov\_report maqsadlari bilan).
- gcov\_report maqsadida html sahifasi shaklida gcov hisoboti shakllantirilishi kerak. Buning uchun unit testlar gcov bayroqlari bilan ishga tushirilishi kerak.
- Har bir funksiyadan oldin s21\_ prefiksidan foydalaning.
- Realizatsiyani nusxalash va satrga ishlov berishda unit testlaridan tashqari standart string.h kutubxonasidan va boshqa kutubxonalardan foydalanish taqiqlanadi.
- POSIX standartlarida (sys\_nerr, sys\_errlist) ko'rsatilmagan ro'yxatlar bilan birga, tizim xatolar ro'yxatidan foydalanish taqiqlanadi. Buning o'rniga, strerror funksiyasi tavsifida aytib o'tilganidek, o'zingizning platformaga bog’liq xatolar ro'yxatini amalga oshirishingiz kerak.
- string.h standart kutubxonasi ish mantig’iga albatta amal qiling (tekshiruvlar, xotira bilan ishlash va shtatli bo’lmagan vaziyatlardagi xatti-harakatlarda – bu yerda testlar yordam beradi).
- Funksiyalar ASCII kodlashda bir baytli belgilardan z-satrlar bilan ishlashi kerak.

## Part 2. sprintf funksiyasini qisman amalga oshirish

stdio.h kutubxonasidan sprintf funksiyasini amalga oshirishingiz kerak:
- Funksiya s21_string.h kutubxonasiga joylashtirilishi kerak.
- Funksiyani amalga oshirish birinchi qismda belgilangan barcha talablarga bo'ysunadi.
- Qisman formatlash qo'llab-quvvatlanishi kerak:
  - Spetsifikatorlar: s, d, f, s, u, %
  - Bayroqlar: -, +, (bo'sh joy)
  - Kenglik: (son)
  - Aniqlik: .(son)
  - Uzunlik: h, I

## Part 3. Qo'shimcha. Ba'zi sprintf funksiyasi formati modifikatorlarini amalga oshirish

Qo'shimcha ballar uchun majburiy bo’lmagan topshiriq: stdio.h kutubxonasidan sprintf funksiyasi uchun ba'zi format modifikatorlarini amalga oshiring:
- Funksiya s21\_string.h kutubxonasiga joylashtirilishi kerak.
- Funksiyani amalga oshirish birinchi qismda belgilangan barcha talablarga bo'ysunadi.
- Quyidagi qoʻshimcha format modifikatorlari qoʻllab-quvvatlanishi kerak:
  - Spetsifikatorlar: g, G, e, E, x, X, o, p
  - Bayroqlar: #, O
  - Kenglik: *
  - Aniqlik: .*
  - Uzunlik: L

## Part 4. Qo'shimcha. sscanf funksiyasini amalga oshirish

Qo'shimcha ballar uchun majburiy bo’lmagan topshiriq: stdio.h kutubxonasidan sscanf funksiyasini amalga oshiring:
- Funksiya s21_string.h kutubxonasiga joylashtirilishi kerak.
- Funksiyani amalga oshirish birinchi qismda belgilangan barcha talablarga bo'ysunadi.
- To'liq formatlash (jumladan, bayroqlar, kenglik, modifikatorlar va aylanish turlari) qo'llab-quvvatlanishi kerak.

## Part 5. Дополнительно. Реализация специальных функций обработки строк

Qo'shimcha ballar uchun majburiy bo’lmagan topshiriq: String sinfidan ba'zi satrga ishlov berish funksiyalarini amalga oshiring:
- Funksiyalar s21_string.h kutubxonasiga joylashtirilishi kerak.
- Funksiyani amalga oshirish, realizatsiyangizni standart bilan solishtirish talabidan tashqari, birinchi qismda belgilangan barcha talablarga bo'ysunadi.
