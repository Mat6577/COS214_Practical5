#include "ResponseComponent.h"
#include "Stages.h" 

void ResponseComponent::requestAlert() {
    if (state) {
        state->handleAlert(this);
    }
}

void ResponseComponent::requestDispatch() {
    if (state) {
        state->handleDispatch(this);
    }
}

void ResponseComponent::requestSecure() {
    if (state) {
        state->handleSecure(this);
    }
}