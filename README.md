Linux Syslog Loglarının Bağlı Liste ile Gösterilmesi

Projenin Amacı

Bu projenin amacı, Linux işletim sisteminde bulunan syslog sistem günlüklerini analiz etmek ve bu günlükleri bağlı liste (Linked List) veri yapısı kullanarak saklayan bir uygulama geliştirmektir.
Linux sistemlerinde oluşan log kayıtları genellikle dosyalarda tutulur. Bu projede ise bu kayıtlar okunarak dinamik bir veri yapısı olan bağlı liste içerisinde saklanmaktadır. Böylece veri yapıları dersinde öğrenilen linked list yapısının gerçek bir sistem verisi üzerinde nasıl kullanılabileceği gösterilmektedir.

Proje Ne Yapar

Bu uygulama Linux sistemindeki syslog kayıtlarını okuyarak bunları bağlı liste veri yapısında saklar ve ekrana yazdırır.
Programın yaptığı işlemler şunlardır:
* Linux sistemindeki syslog dosyasını okur
* Her log kaydını bir düğüm (node) olarak oluşturur
* Bu düğümleri tek yönlü bağlı liste yapısına ekler
* Tüm log kayıtlarını sıralı şekilde ekrana yazdırır
* Sistemde bulunan toplam log sayısını hesaplayabilir
* İstenirse hata (error) içeren logları filtreleyerek gösterebilir
Bu sayede syslog verileri dinamik bir veri yapısı içerisinde saklanarak analiz edilebilir.

Nasıl Kurulur

Projeyi çalıştırmak için öncelikle bir Linux ortamına ihtiyaç vardır.
1. GitHub reposunu bilgisayarınıza indirin veya klonlayın.
git clone https://github.com/kullaniciadi/linux-syslog-linkedlist.git
1. Proje klasörüne gidin.
cd linux-syslog-linkedlist
1. Sisteminizde GCC derleyicisinin kurulu olduğundan emin olun.
GCC kontrolü:
gcc --version

Nasıl Çalıştırılır

Programı çalıştırmak için aşağıdaki adımlar uygulanır.
1. Programı derleyin:
gcc syslog_linkedlist.c -o syslog
1. Programı çalıştırın:
./syslog

Program çalıştırıldığında syslog dosyası okunacak ve log kayıtları bağlı liste içerisinde tutulup ekrana yazdırılacaktır.

Kullanılan Teknolojiler

* C Programlama Dili
* Linux İşletim Sistemi
* Syslog Log Sistemi
* Linked List Veri Yapısı
* GCC Derleyicisi
* GitHub Versiyon Kontrol Sistemi

Bu proje, veri yapıları dersinde öğrenilen bağlı liste yapısının gerçek bir sistem verisi olan Linux syslog kayıtları üzerinde uygulanmasını göstermektedir.

Linux syslog 

1. Syslog Mekanizması Nedir?

Syslog, Linux ve Unix tabanlı işletim sistemlerinde kullanılan standart bir sistem günlükleme (logging) mekanizmasıdır.

Syslog Ne İçin Kullanılır?
Sistem İzleme:
Sistemde çalışan servislerin durumunu ve sistem olaylarını takip etmek için kullanılır. Örneğin bir servis başlatıldığında veya durdurulduğunda bu olay syslog kayıtlarına yazılır.

Hata Tespiti ve Analizi:
Programlar veya servisler çalışırken oluşan hatalar syslog kayıtlarına yazılır. Bu sayede sistem yöneticileri hataların nedenini inceleyebilir.

Güvenlik Takibi:
Başarısız giriş denemeleri, yetkisiz erişim girişimleri ve güvenlik olayları syslog kayıtlarında tutulur. Bu kayıtlar güvenlik analizinde önemli rol oynar.

Sistem Performansı ve Davranış Analizi:
Sistem kaynaklarının kullanımı ve sistem davranışı log kayıtları incelenerek analiz edilebilir.

Seçilen Bağlı Liste Türünün Syslog Kayıtlarıyla İlgisi;
Bu projede tek yönlü bağlı liste (Singly Linked List) tercih edilmiştir. Bunun nedeni syslog kayıtlarının zaman sırasına göre sürekli olarak oluşmasıdır.
Sistemde yeni bir olay gerçekleştiğinde yeni bir log kaydı oluşur ve bu kayıt listenin sonuna eklenebilir. Tek yönlü bağlı liste bu işlemi kolay ve hızlı bir şekilde yapmaya uygundur.
Ayrıca syslog kayıtları genellikle baştan sona doğru okunur ve geriye doğru dolaşmaya ihtiyaç duyulmaz. Bu nedenle daha basit ve daha az bellek kullanan tek yönlü bağlı liste kullanmak daha uygun bir çözümdür.
