import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
// importujemy biblioteke dla form
import { FormsModule } from '@angular/forms';
import { AppComponent } from './app.component';

@NgModule({
  declarations: [
    AppComponent
  ],
  imports: [ // do importowc dodajemy FormsModule
    BrowserModule,
    FormsModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
