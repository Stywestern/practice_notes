# project_constants.py

# Mapping index to Region Name for the 26x26 matrix These correspond to the regions in master_dataset.csv.
REGIONS = [
    "Adana, Mersin-TR62", "Ağrı, Kars, Iğdır, Ardahan-TRA2", "Ankara-TR51",
    "Antalya, Isparta, Burdur-TR61", "Aydın, Denizli, Muğla-TR32",
    "Balıkesir, Çanakkale-TR22", "Bursa, Eskişehir, Bilecik-TR41",
    "Erzurum, Erzincan, Bayburt-TRA1", "Gaziantep, Adıyaman, Kilis-TRC1",
    "Hatay, Kahramanmaraş, Osmaniye-TR63", "İstanbul-TR10", "İzmir-TR31",
    "Kastamonu, Çankırı, Sinop-TR82", "Kayseri, Sivas, Yozgat-TR72",
    "Kırıkkale, Aksaray, Niğde, Nevşehir, Kırşehir-TR71",
    "Kocaeli, Sakarya, Düzce, Bolu, Yalova-TR42", "Konya, Karaman-TR52",
    "Malatya, Elazığ, Bingöl, Tunceli-TRB1", "Manisa, Afyonkarahisar, Kütahya, Uşak-TR33",
    "Mardin, Batman, Şırnak, Siirt-TRC3", "Samsun, Tokat, Çorum, Amasya-TR83",
    "Şanlıurfa, Diyarbakır-TRC2", "Tekirdağ, Edirne, Kırklareli-TR21",
    "Trabzon, Ordu, Giresun, Rize, Artvin, Gümüşhane-TR90",
    "Van, Muş, Bitlis, Hakkari-TRB2", "Zonguldak, Karabük, Bartın-TR81"
]

ADJACENCY_DICT = {
    "Adana, Mersin-TR62": ["Antalya, Isparta, Burdur-TR61", "Konya, Karaman-TR52", "Kayseri, Sivas, Yozgat-TR72", "Hatay, Kahramanmaraş, Osmaniye-TR63", "Kırıkkale, Aksaray, Niğde, Nevşehir, Kırşehir-TR71"],
    "Ağrı, Kars, Iğdır, Ardahan-TRA2": ["Erzurum, Erzincan, Bayburt-TRA1", "Van, Muş, Bitlis, Hakkari-TRB2"],
    "Ankara-TR51": ["Konya, Karaman-TR52", "Kırıkkale, Aksaray, Niğde, Nevşehir, Kırşehir-TR71", "Kayseri, Sivas, Yozgat-TR72", "Bursa, Eskişehir, Bilecik-TR41", "Kastamonu, Çankırı, Sinop-TR82", "Kocaeli, Sakarya, Düzce, Bolu, Yalova-TR42"],
    "Antalya, Isparta, Burdur-TR61": ["Aydın, Denizli, Muğla-TR32", "Manisa, Afyonkarahisar, Kütahya, Uşak-TR33", "Konya, Karaman-TR52", "Adana, Mersin-TR62"],
    "Aydın, Denizli, Muğla-TR32": ["İzmir-TR31", "Manisa, Afyonkarahisar, Kütahya, Uşak-TR33", "Antalya, Isparta, Burdur-TR61"],
    "Balıkesir, Çanakkale-TR22": ["Tekirdağ, Edirne, Kırklareli-TR21", "Bursa, Eskişehir, Bilecik-TR41", "Manisa, Afyonkarahisar, Kütahya, Uşak-TR33", "İzmir-TR31"],
    "Bursa, Eskişehir, Bilecik-TR41": ["Balıkesir, Çanakkale-TR22", "Manisa, Afyonkarahisar, Kütahya, Uşak-TR33", "Kocaeli, Sakarya, Düzce, Bolu, Yalova-TR42", "Ankara-TR51", "Konya, Karaman-TR52"],
    "Erzurum, Erzincan, Bayburt-TRA1": ["Trabzon, Ordu, Giresun, Rize, Artvin, Gümüşhane-TR90", "Ağrı, Kars, Iğdır, Ardahan-TRA2", "Van, Muş, Bitlis, Hakkari-TRB2", "Malatya, Elazığ, Bingöl, Tunceli-TRB1", "Kayseri, Sivas, Yozgat-TR72"],
    "Gaziantep, Adıyaman, Kilis-TRC1": ["Hatay, Kahramanmaraş, Osmaniye-TR63", "Şanlıurfa, Diyarbakır-TRC2", "Malatya, Elazığ, Bingöl, Tunceli-TRB1"],
    "Hatay, Kahramanmaraş, Osmaniye-TR63": ["Adana, Mersin-TR62", "Kayseri, Sivas, Yozgat-TR72", "Gaziantep, Adıyaman, Kilis-TRC1", "Malatya, Elazığ, Bingöl, Tunceli-TRB1"],
    "İstanbul-TR10": ["Tekirdağ, Edirne, Kırklareli-TR21", "Kocaeli, Sakarya, Düzce, Bolu, Yalova-TR42"],
    "İzmir-TR31": ["Balıkesir, Çanakkale-TR22", "Manisa, Afyonkarahisar, Kütahya, Uşak-TR33", "Aydın, Denizli, Muğla-TR32"],
    "Kastamonu, Çankırı, Sinop-TR82": ["Zonguldak, Karabük, Bartın-TR81", "Kocaeli, Sakarya, Düzce, Bolu, Yalova-TR42", "Ankara-TR51", "Kırıkkale, Aksaray, Niğde, Nevşehir, Kırşehir-TR71", "Samsun, Tokat, Çorum, Amasya-TR83"],
    "Kayseri, Sivas, Yozgat-TR72": ["Ankara-TR51", "Kırıkkale, Aksaray, Niğde, Nevşehir, Kırşehir-TR71", "Adana, Mersin-TR62", "Hatay, Kahramanmaraş, Osmaniye-TR63", "Malatya, Elazığ, Bingöl, Tunceli-TRB1", "Erzurum, Erzincan, Bayburt-TRA1", "Samsun, Tokat, Çorum, Amasya-TR83"],
    "Kırıkkale, Aksaray, Niğde, Nevşehir, Kırşehir-TR71": ["Ankara-TR51", "Konya, Karaman-TR52", "Adana, Mersin-TR62", "Kayseri, Sivas, Yozgat-TR72", "Kastamonu, Çankırı, Sinop-TR82"],
    "Kocaeli, Sakarya, Düzce, Bolu, Yalova-TR42": ["İstanbul-TR10", "Bursa, Eskişehir, Bilecik-TR41", "Ankara-TR51", "Kastamonu, Çankırı, Sinop-TR82", "Zonguldak, Karabük, Bartın-TR81"],
    "Konya, Karaman-TR52": ["Ankara-TR51", "Bursa, Eskişehir, Bilecik-TR41", "Manisa, Afyonkarahisar, Kütahya, Uşak-TR33", "Antalya, Isparta, Burdur-TR61", "Adana, Mersin-TR62", "Kırıkkale, Aksaray, Niğde, Nevşehir, Kırşehir-TR71"],
    "Malatya, Elazığ, Bingöl, Tunceli-TRB1": ["Kayseri, Sivas, Yozgat-TR72", "Hatay, Kahramanmaraş, Osmaniye-TR63", "Gaziantep, Adıyaman, Kilis-TRC1", "Şanlıurfa, Diyarbakır-TRC2", "Mardin, Batman, Şırnak, Siirt-TRC3", "Van, Muş, Bitlis, Hakkari-TRB2", "Erzurum, Erzincan, Bayburt-TRA1"],
    "Manisa, Afyonkarahisar, Kütahya, Uşak-TR33": ["İzmir-TR31", "Balıkesir, Çanakkale-TR22", "Bursa, Eskişehir, Bilecik-TR41", "Konya, Karaman-TR52", "Antalya, Isparta, Burdur-TR61", "Aydın, Denizli, Muğla-TR32"],
    "Mardin, Batman, Şırnak, Siirt-TRC3": ["Şanlıurfa, Diyarbakır-TRC2", "Malatya, Elazığ, Bingöl, Tunceli-TRB1", "Van, Muş, Bitlis, Hakkari-TRB2"],
    "Samsun, Tokat, Çorum, Amasya-TR83": ["Kastamonu, Çankırı, Sinop-TR82", "Kayseri, Sivas, Yozgat-TR72", "Trabzon, Ordu, Giresun, Rize, Artvin, Gümüşhane-TR90"],
    "Şanlıurfa, Diyarbakır-TRC2": ["Gaziantep, Adıyaman, Kilis-TRC1", "Malatya, Elazığ, Bingöl, Tunceli-TRB1", "Mardin, Batman, Şırnak, Siirt-TRC3"],
    "Tekirdağ, Edirne, Kırklareli-TR21": ["İstanbul-TR10", "Balıkesir, Çanakkale-TR22"],
    "Trabzon, Ordu, Giresun, Rize, Artvin, Gümüşhane-TR90": ["Samsun, Tokat, Çorum, Amasya-TR83", "Erzurum, Erzincan, Bayburt-TRA1"],
    "Van, Muş, Bitlis, Hakkari-TRB2": ["Ağrı, Kars, Iğdır, Ardahan-TRA2", "Erzurum, Erzincan, Bayburt-TRA1", "Malatya, Elazığ, Bingöl, Tunceli-TRB1", "Mardin, Batman, Şırnak, Siirt-TRC3"],
    "Zonguldak, Karabük, Bartın-TR81": ["Kastamonu, Çankırı, Sinop-TR82", "Kocaeli, Sakarya, Düzce, Bolu, Yalova-TR42"]
}

QUEEN_MATRIX = [[0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                [0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0],
                [0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                [1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0], 
                [0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0], 
                [0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0], 
                [0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0], 
                [0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0], 
                [0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0], 
                [1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0], 
                [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0], 
                [0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0], 
                [0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1], 
                [1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0], 
                [1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0], 
                [0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1], 
                [1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0], 
                [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0], 
                [0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0], 
                [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0], 
                [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0], 
                [0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0], 
                [0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], 
                [0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0], 
                [0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0], 
                [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]]

# Bayesian Priors for Beta
BETA_PRIOR_MEAN = 0
BETA_PRIOR_VAR = 1e5


