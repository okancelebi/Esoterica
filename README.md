# Esoterica Prototype Game Engine

![Esoterica Logo](Docs/EE_Logo.png)

[Esoterica Engine](https://www.esotericaengine.com) Esoterica Engine, MIT lisanslı bir prototip oyun motoru iskeletidir. Bir teknoloji göstericisi, bir eğitim aracı ve bir Ar-Ge iskeleti olarak tasarlanmıştır. Kaynak yönetimi, seri hale getirme, oyun oynama vb. için gereken çok sayıda standart makine içerir. Potansiyel olarak bir kaynak sisteminin nasıl oluşturulacağı, temel yansıma ve AAA düzeyinde bir animasyon sisteminin nasıl oluşturulacağı konusunda birçok referans sağlar. Oyun, yapay zeka, oluşturucu teknolojisi veya oyun motorlarının nasıl oluşturulacağı konusunda bir öğretim yardımcısı olarak denemeler yapmak için iyi bir iskelet olabilir. Ek olarak, kendi motorunuzu yapmakla daha çok ilgileniyorsanız, Esoterica gerçekten iyi bir başlangıç noktasıdır.

## Önemli Not: İstikrar!

>Esoterica, boş zamanlarımızda geliştirilmekte olan bir prototip motordur ve bu nedenle muhtemelen hatalar ve çökmeler olacaktır (öncelikle takım tarafında). İstikrarlı bir üretim aracı olarak tasarlanmamıştır. Herhangi bir çökme veya hatayla karşılaşırsanız, lütfen sorunları bildirin, elimizden gelen en kısa sürede onlara ulaşmaya çalışacağız.

## Yardım Gerekli: Oluşturma + Test Varlıkları

Herkese açık olarak yayınlayabileceğim herhangi bir varlığımız olmadığı için maalesef sağlanan hiçbir teknolojinin örneği yok. Motorla birlikte dağıtabileceğimiz bazı test varlıkları oluşturabilecek arkadaşlar arıyoruz (örneğin, bir karakter modeli ve bazı animasyonlar). Daha sonra bu varlıkları çeşitli araç ve özelliklere ilişkin bir dizi örnek sağlamak için kullanabiliriz.

Ayrıca, renderer oluşturmamıza yardımcı olacak birini arıyoruz. Daha fazla ayrıntı burada bulunabilir: https://www.esotericaengine.com/contribute

## Neler dahil

* Bir oyun motorunun temel çekirdeği (seri hale getirme, matematik, dizi işleme, günlük kaydı vb.)
* Libclang tabanlı c++ yansıma ve kod oluşturma
* Çalışırken yeniden yüklemeli derleyici tabanlı kaynak sistemi
* Hibrit Aktör/ECS nesne modeli - <https://www.youtube.com/watch?v=jjEsB611kxs>
* AAA kalitesinde yüksek performanslı animasyon grafik sistemi - <https://www.youtube.com/watch?v=R-T3Mk5oDHI&t=5427s>
* Temel animasyon sıkıştırması
* PhysX artikülasyonlarını kullanarak güçlendirilmiş Ragdoll uygulaması
* DearImgui kullanarak temel editör altyapısı ve araçları

## Ekran görüntüleri

|Kaynak İşlem Hattı | Temel Düzenleyici |
|:---:|:---:|
|![Esoterica Kaynak Sunucusu](Docs/EE_ResourceServer.png)|![Esoterica Editor](Docs/EE_Editor.png)|

| Animasyon Grafiği | Ragdoll Editörü |
|:---:|:---:|
|![Esoterica Animasyon Grafiği](Docs/EE_AnimGraph.png)|![Esoterica Ragdoll](Docs/EE_Ragdoll.png)|

## Gereksinimler

* Visual Studio 2022
* FBX SDK

## Esoterica Binası

Esoterica, yapı sistemi için vanilya msbuild kullanıyor. "code/property sheets" klasöründe Esoterica için tüm yapı ayarlarını kontrol eden bir dizi özellik sayfası vardır.

1. Dış bağımlılıkları indirin ve Esoterica kök klasörüne (X:/Esoterica Path/) ayıklayın. 'X:/Esoterica Path/External/' ile bitirmelisiniz.
2. FBX SDK'yı indirin ve kurun (düzenleyici için gereklidir) - <https://www.autodesk.com/developer-network/platform-technologies/fbx-sdk-2020-2-1>
3. Çözümü aç "Esoterica.sln"
4. "Esoteria.Scripts.Reflect" projesini YENİDEN YAPIN ("0. Scripts" çözüm klasörü altında) - bu, tüm Esoterica yansıma verilerini oluşturacaktır.
5. "1. Applications" çözüm klasörünü oluşturun - bu, Esoterica'nın çalışması için gereken tüm uygulamaları oluşturacaktır.

## Uygulamalar

Başlamanın en kolay yolu, "Ezoterica.Applications.Editor" dosyasını başlangıç projesi olarak ayarlamak ve çalıştırmaya basmaktır. Motoru çalıştırmak istiyorsanız, "-map data://path_to_map.map" argümanıyla "Esoterica.Applications.Engine" projesini kullanın.

* Motor - bu bağımsız Esoterica motor istemcisidir
* Editör - Bu Esoterica editörü
* Kaynak Sunucusu - Bu, çeşitli Esoterica uygulamalarına kaynak sağlayacak ve derleyecek bağımsız bir uygulamadır.
* Reflektör - Bu, Esoterica yansıma verilerini oluşturur
* Kaynak Derleyici - Bu, kaynak derleme isteklerini işler
* Test Cihazı - Rastgele test için kullanılan boş konsol uygulaması

## Thirdparty projects used

* EASTL
* DearImgui
* EnkiTS
* iniparser
* PCG
* xxhash
* rpmalloc
* concurrentqueue
* MPack
* Game Networking Sockets
* PhysX
* cgltf
* pfd
* sqlite
* subprocess
* optick

Bu ara yazılım paketleri de entegredir ancak kullanım için bir lisans gerektirir (bu nedenle varsayılan olarak devre dışı bırakılırlar)

* Live++
* Superluminal
* Navpower

## Ekstra Bilgi

VS için SmartCommandLineArguments eklentisini kullanırsanız, motoru çalıştırmanıza yardımcı olacak kaydedilmiş argümanlar sağlanır.
