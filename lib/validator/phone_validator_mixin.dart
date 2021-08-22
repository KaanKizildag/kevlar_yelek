class PhoneValidatorMixin{
  String validatePhone(String value){
    if(!value.startsWith('+90')){
      return 'Lütfen geçerli bir telefon numarası girin\n(+90 ile başlamalı)';
    }

    if(value.length != 13){
      return 'Lütfen geçerli bir telefon numarası girin\nnumara, 13 haneden oluşmalı';
    }
  }
}