# STRUKTURALI DASTURLASH TAMOYILLARI

Strukturali dasturlashning shakllanishi va rivojlanishi Edsger Deykstra nomi bilan bog’liq.
* 1-tamoyil: goto operatoridan foydalanishdan saqlaning.
* 2-tamoyil. Har qanday dastur uchta asosiy boshqaruv tuzilmasidan qurilgan: ketma-ketlik, tarmoqlash, davr.
* 3-tamoyil. Dasturda asosiy boshqaruv tuzilmalari bir-birining ichiga har qanday usulda joylashtirilishi mumkin. Operatsiyalar bajarilishining ketma-ketligini nazorat qilishning boshqa hech qanday vositalari yo’q.
* 4-tamoyil. Takroriy dastur fragmentlari quyi dasturlar (protseduralar va funksiyalar) sifatida formatlanishi mumkin. Xuddi shu tarzda (subprogrammalar ko’rinishida) dasturning mantiqiy integral bo’laklarini hatto ular takrorlanmasa ham tartibga solish mumkin.
* 5-tamoyil. Har bir mantiqiy to'liq ko'rsatmalar guruhi blok sifatida ishlab chiqilishi kerak. Bloklar tuzilgan dasturlashning asosidir.
* 6-tamoyil. Barcha sanab o’tilgan tuzilmalar bitta kirish va bitta chiqishga ega bo’lishi kerak.
* 7-tamoyil. Dasturni ishlab chiqish bosqichma-bosqich, “yuqoridan pastga” usuli yordamida amalga oshiriladi.

Yuqoridagi printsiplarga xulosalar va qo’shimchalar:

1. Global o’zgaruvchilardan foydalanishni taqiqlash
2. Bittadan ortiq funktsiyadan chiqish mumkin emas. Istisno - bu funktsiya argumentlarini dastlabki tekshirish.
3. Davrdan bir martadan ortiq chiqish mumkin emas - bu shart yoki break kalit so’zi bo’lishi mumkin
4. Har qanday bloklarning uyasi 4 dan oshmasligi kerak.
5. Funksiyalar hajmi satrlar bilan chegaralangan va 40-50 qatorni tashkil qiladi.
