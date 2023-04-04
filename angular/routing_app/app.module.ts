import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
import { compileNgModule } from '@angular/compiler';
import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { FirstComponent } from './first/first.component';
import { SecondComponent } from './second/second.component';
import { PagenotfoundComponent } from './pagenotfound/pagenotfound.component';
import { ChildAComponent } from './child-a/child-a.component';
import { ChildBComponent } from './child-b/child-b.component';
import { FormsModule } from '@angular/forms';

@NgModule({
  declarations: [
    AppComponent,
    FirstComponent,
    SecondComponent,
    PagenotfoundComponent,
    ChildAComponent,
    ChildBComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    FormsModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
