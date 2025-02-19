# Sinovlarni ishga tushirish bo’yicha ko’rsatmalar

To’g’ri chiqish ma’lumotlarini sinovdan o’tkazishga qo’shimcha ravishda, ushbu avtotest tizimi dasturing va uning manba kodini quyidagi bandlar bo’yicha tekshiradi: 

* **Uslubiy testlar.** Kodingning go’zalligi standartlarga naqadar mos kelishini tekshirish uchun sen clang-format utiliti yordamida dasturidan foydalanib kodingni sinab ko’rishing mumkin. ```materials/linters``` papkasida uslub testi uchun kerakli sozlamalarni o’z ichiga olgan ```.clang-format``` fayli mavjud. Ushbu konfiguratsiya fayli o’z ta’sirini direktoriyada yoki pastroqdagi direktoriyalarda joylashgan barcha fayllarga qo’llaydi. Shuning uchun, ushbu sozlamalar asosiy koding bo’lgan fayllaringga qo’llanilishi uchun.    
  ```clang-format``` ```src``` papkasiga nusxala. \
  \
  Uslubni tekshirish uchun quyidagi buyruqni bajar: \
  ```clang-format -n src/sourcefile_name.c```

  _clang-format_ yuklab olish uchun terminalga quyidagi buyruqlardan birini kirit: \
  ```brew install clang-format``` \
  yoki, agar senda root huquqlari bo’lsa (Ubuntu / Linux Mint / Debian uchun) \
  ```sudo apt install clang-format```

  Kerakli clang-format versiyasi: \
  **Mac** 18.1.8 \
  **Linux** 18.1.8

  Google Style: https://google.github.io/styleguide/cppguide.html

* **Xotiraning to'g'ri ishlashini sinash.** C dasturlarini yozishda xotiraning oqishiga e'tibor berish juda muhimdir. Buning uchun Unix-ga o'xshash operatsion tizimlarda ko'pincha _valgrind_ utilitasi qo'llaniladi. Biroq, OS X da _valgrind_ qo’llab-quvvatlashda muammolar mavjud, shuning uchun uning o’rniga _leaks_ utilitasidan foydalanish mumkin.

  Hozir ushbu utilitalar ishlash mexanizmini ko’rib chiqmaymiz - agar qiziq bo’lda, Googleda o'qishing mumkin.

**_LEAKS_**

  Ushbu yordamchi dastur yordamida bajariladigan faylni ishga tushirish uchun terminalga kirit:
  ```leaks -atExit -- ./main.out | grep LEAK:```

  ```| grep LEAK:``` buyrug’iga e’tibor ber. Biz uni qisqa chiqish uchun ishlatamiz, shunda biz agar mavjud bo'lsa faqat oqishlar bo’lgan chiziqlarni ko'rishimiz mumkin. Agar sen butun chiqarishni ko’rishni istasang, shunchaki bu buyruqni o’chirib tashla.

  _leaks_ yordamida bajariladigan faylni ishga tushirishda, xatolik to’g’risidagi xabar paydo bo’lishi mumkin:
  > dyld: could not load inserted library ‘/usr/local/lib/libLeaksAtExit.dylib’ because image not found

  _leaks_ kutubxonani topa olmaganligi sababli xatolik yuzaga keladi _libLeaksAtExit.dylib_. \  
  Bunday holda quyidagi buyruqlarni kiritish kerak:
  ```sh
  cd /usr/local/lib
  sudo ln -s /Applications/Xcode.app/Contents/Developer/usr/lib/libLeaksAtExit.dylib
  ```

  _Qo’shimcha:_ \
  Xotirada oqish borligi maʼlum boʻlgan funksiyalardagi oqib chiqishlarni filtrlash uchun leaks utilitasining ```-exclude``` bayrogʻidan foydalan. Bu bayroq _leaks_ tomonidan berilayotgan ma’lumotlarning oqishini kamaytirish imkonini beradi.

**_VALGRIND_**

  _valgrind_ kompyuterga o’rnatish uchun quyidagi buyruqlardan birini kirit: \
  ```brew install valgrind``` \
  yoki, agar sizda ildiz huquqlari bo'lsa (Ubuntu / Linux Mint / Debian uchun) \
  ```sudo apt install valgrind``` \
  Ushbu utilita  yordamida bajariladigan faylni ishga tushirish uchun terminalga kirit: \
  ```valgrind --tool=memcheck --leak-check=yes ./main.out```

  OS X da _valgrind_ foydalanish tavsiya etilmaydi, buning o’rniga _leaks_ ishlatish yaxshiroqdir

* **Qo‘shimcha xotiraning to’g’ri ishlashini tekshirish.** Yana bir variant sifatida xotirani qayta ishlashning to'g'riligini tekshirish va xotira oqishini kuzatish - ```gcc``` ichiga o'rnatilgan AddressSanitizer utilitalaridan foydalanish. Shu o’rinda ta’kidlab o’tamizki, uni leaks yoki ```valgrind``` alohida ishlatish kerak, chunki u kompilyatsiyadan keyin avtomatik ravishda binary faylga o’rnatiladi va ushbu utilitalar bilan mos kelmasligi mumkin.

Uni kompilyatsiyalash paytida ishlatish uchun ```-fsanitize=address``` bayrog'ini belgilaymiz.

**Masalan:**

```gcc -o main main.c -fsanitize=address ```

Va yig’ilgan dasturni odatdagi tarzda ishga tushiramiz. Bunday holda, xotira bilan bog’liq xatolar mavjud bo’lsa, ular konsolda ko’rsatiladi.

```-fsanitize=address``` bayrog'idan tashqari quyidagi bayroqlardan ham foydalanish mumkin: 
* ```-fsanitize=leak``` - xotira oqishini kuzatish uchun. Shuningdek, qo’shimcha ravishda leaks yoki valgrind yordamida oqishlarni tekshirishni ham unutma.
* ```-fsanitize=undefined``` - aniqlanmagan dastur harakati joylarini aniqlash uchun (masalan, massiv chegarasidan tashqariga chiqish yoki int’ni haddan tashqari to’lishi).
* ```-fsanitize=unreachable``` - erishib bo'lmaydigan dastur nuqtalarini aniqlash uchun.

Yanada ko’proq bayroqlarni gcc va AddressSanitizer hujjatlarida topishing mumkin.
