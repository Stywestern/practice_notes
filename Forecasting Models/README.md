# Karaca Öngörü Modelleri projesi içeriği hakkında

## Giriş
Bu proje Karaca Mağazacılık satış verileri ile öngörü modelleri eğitmek, sık kullanılan modelleri bu spesifik görevde karşılaştırmak ve iş arkadaşlarıma Yapay Zeka modellerinin demosunu bırakmak adına oluşturulmuştur.
Projenin içerdiği notebook'ları farklı veriler kullanılıp başka hedefler istenilmesi halinde rahatça değiştirelebilecek şekilde modüler oluşturmaya çalıştım. Amacım ileride bu tür YZ geliştirmeleri yapılmak istenirse bunlar için bir altyapı sağlayabilmekti.

## Projenin içeriği
### Klasörler ve dosyalar
* DATASETS: İşlenmemiş ve işlenmiş verileri tutar
* MODELS: Eğitilmiş ve uygulama için seçilmiş son modelleri tutar
* RNN Model Graphs: Recurrent Neural Network modellerini iç mimarisini gösteren görüntüleri tutar
* saved_GRU ve saved_LSTM: RNN modellerinin epoch başına eğitildikleri parametreleri tutar
* catboost_info: Categorical Boosting algoritmasının eğitilmesi ile ilgili bilgiler tutar
* column_docs: Ham verinin sütunları ile alakalı bilgileri tutar
* normalization_stats: Normalizasyon istatistiklerini saklar

### Notebook'lar
Notebook'ları 4 grup halinde sınıflandırmak mümkün
1) Veri Analizi Notebook'ları: Verileri incelemek ve değiştirmek için kullanılan notebook'lar
   * EDA 1 (General).ipynb: Veriye genel bir bakış
   * EDA 2 (Descriptive Statistics).ipynb: Sütunlar hakkında detaylı bilgi
   * EDA 3 (Further Cleaning).ipynb: Veriyi hedef ve istekler doğrultusunda temizleme
2) Model Notebook'ları: Modellerin eğitildikleri, değerlendirildikleri ve açıklandıkları notebook'lar
   * RNN Models - Main.ipynb: RNN modelleri hakkında ana notebook
   * RNN Models - Prototype.ipynb: Ana RNN modellerinin sekans büyüklüğü birden fazla olmayan hali
   * Linear Models.ipynb: Lineer regresyon modelleri
   * Tree Models.ipynb: Ağaç modelleri
   * ARIMA Models.ipynb: ARIMA modelleri
   * Prophet Models.ipynb: Meta'nın geliştirdiği açık kaynak kodlu öngörü algoritması
3) Uygulama Notebook'ları: Gradio kütüphanesi kullanılarak oluşturulmuş, kullanıcı arayüzü oluşturmaya yarayan notebook'lar 
   * Gradio - RNN.ipynb: RNN modelleri için Gradio
   * Gradio - Linear.ipynb: En iyi lineer model için Gradio
   * Gradio - Tree.ipynb: En iyi ağaç modeli için Gradio
   * Gradio - Prophet.ipynb: En iyi Prophet modeli için Gradio
4) İşlevsel Notebook: İçinde birkaç fonksiyon barındıran bir notebook
   * Utilities.ipynb
  
## Yazar tarafından önerilen görüntüleme sıralaması
Notebook'ların çoğu kendi içinde bir bütün olarak çalışabilir, ancak birbirleri ile birçok ortak fonksiyon ve bölüm içeriyorlar. Okuyucu için daha rahat olması adına sürekli aynı açıklamaları yapmaktan kaçınmak istedim. Bu yüzden aynı gruptaki notebook'lar için genel açıklamaları her grubun ilk elemanı olarak yazdığım notebook'a koydum. Diğer notebook'larda da aynı grupta diğerlerinde olmayan kısımların açıklamaları bulunuyor. "Notebook'lar" kısımında sıralandığı gibi okursanız tüm açıklamaları görebilirsiniz.

## Notlar
