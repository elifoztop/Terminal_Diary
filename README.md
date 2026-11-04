# 📔 Terminal Diary

C dilinde yazılmış, terminalde çalışan basit bir kişisel günlük uygulaması.

Bu proje, C dilinde **dosya işlemlerini** (dosya açma, yazma, okuma ve kapatma) pratik ederek öğrenmek amacıyla geliştirildi. Kullanıcının yazdığı günlük sayfaları, o günün tarihiyle birlikte bir metin dosyasına kaydedilir ve istendiğinde tekrar okunabilir.

## ✨ Özellikler

- Yeni günlük sayfası açma ve kaydetme
- Her kayda o günün tarihini otomatik ekleme
- Daha önce yazılmış tüm günlük sayfalarını okuma
- Kayıtları kalıcı olarak `gunluk.txt` dosyasında saklama
- Basit, menü tabanlı terminal arayüzü

## 📚 Bu Projede Kullanılan C Konuları

| Konu | Kullanım |
|------|----------|
| `fopen()` | Dosyayı `"a"` (ekleme) ve `"r"` (okuma) kipinde açma |
| `fprintf()` / `fputs()` | Dosyaya biçimlendirilmiş ve düz metin yazma |
| `fscanf()` | Dosyadan kelime kelime okuma |
| `fclose()` | Dosyayı kapatma |
| `NULL` kontrolü | Dosya açılamadığında hatayı yakalama |
| `fgets()` / `strcspn()` | Kullanıcıdan güvenli satır alma ve sondaki `\n` karakterini silme |
| `time()` / `localtime()` | `time.h` ile güncel tarihi alma |
| `switch` ve `while` | Menü döngüsü |
| Fonksiyonlar | `yeni_gunluk()` ve `gunluk_oku()` ile işlemleri ayırma |

Yeni kayıtlar `"a"` kipiyle eklendiği için eski sayfalar silinmez; her yeni sayfa dosyanın sonuna yazılır. Dosya henüz yoksa ilk kayıtta otomatik olarak oluşturulur.

## 🛠️ Kurulum ve Çalıştırma

Depoyu klonlayın:

```bash
git clone https://github.com/elifoztop/Terminal_Diary.git
cd Terminal_Diary
```

GCC ile derleyip çalıştırın:

```bash
gcc main.c -o gunluk
./gunluk
```

Windows'ta çalıştırmak için `gunluk.exe` yazmanız yeterlidir. Proje Code::Blocks ile de açılıp derlenebilir.

## 💻 Kullanım

Program açıldığında aşağıdaki menü gelir:

```
	___<3_Kisisel_Gunluk_Tutma_Platformuna_Hosgeldin_<3___

1- Yeni bir gunluk sayfasi ac
2- Eski gunluk sayfalarini oku
3- Tekrar gorusmek uzere

Secimin:
```

**1** seçildiğinde tarih ekrana yazılır ve günlüğünüzü yazmanız istenir. Yazınızı bitirip Enter'a bastığınızda sayfa kaydedilir.

```
Tarih: 04/11/2026
Merhaba Sevgili Gunluk;
Bugun C ile dosya islemlerini calistim
```

**2** seçildiğinde daha önce yazılan tüm sayfalar sırayla ekrana gelir. **3** programı kapatır.

## 🗂️ Dosya Biçimi

Kayıtlar `gunluk.txt` dosyasında tutulur. Satır sonları, dosyaya gerçek bir alt satır karakteri yerine `/n` işaretiyle yazılır:

```
04/11/2026 /n Merhaba Sevgili Gunluk; /n Bugun C ile dosya islemlerini calistim /n /n
```

Okuma sırasında dosya `fscanf()` ile kelime kelime taranır; `/n` işaretine rastlandığında ekrana alt satıra geçilir, diğer kelimeler aralarına boşluk konularak yazdırılır.

## ⚠️ Bilinen Sınırlamalar

- Bir günlük sayfası tek satırdan oluşur; Enter'a basıldığında kayıt tamamlanır.
- Bir sayfa en fazla yaklaşık 1000 karakter olabilir.
- Okuma kelime kelime yapıldığı için metindeki art arda boşluklar tek boşluk olarak görünür.
- Metnin içinde `/n` yazılırsa, okurken satır sonu olarak yorumlanır.
- Türkçe karakter desteği terminalin karakter kodlamasına bağlıdır.

## 🚀 Geliştirme Fikirleri

- Çok satırlı günlük yazabilme (ör. boş satır girilince kaydı bitirme)
- Satır sonlarını gerçek `\n` olarak kaydedip `fgets()` ile satır satır okuma
- Belirli bir tarihe ait sayfayı arama
- Günlük sayfası silme veya düzenleme
- Saat bilgisini de kaydetme
- Her güne ayrı bir dosya oluşturma
- Günlüğü şifreyle koruma

## 👩‍💻 Geliştirici

**Elif Öztop** · [GitHub](https://github.com/elifoztop)
