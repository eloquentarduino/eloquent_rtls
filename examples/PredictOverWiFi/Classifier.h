#ifndef UUID139870984623536
#define UUID139870984623536

/**
  * RandomForestClassifier(base_estimator=DecisionTreeClassifier(), bootstrap=True, ccp_alpha=0.0, class_name=RandomForestClassifier, class_weight=None, criterion=gini, estimator_params=('criterion', 'max_depth', 'min_samples_split', 'min_samples_leaf', 'min_weight_fraction_leaf', 'max_features', 'max_leaf_nodes', 'min_impurity_decrease', 'min_impurity_split', 'random_state', 'ccp_alpha'), max_depth=8, max_features=auto, max_leaf_nodes=None, max_samples=None, min_impurity_decrease=0.0, min_impurity_split=None, min_samples_leaf=1, min_samples_split=2, min_weight_fraction_leaf=0.0, n_estimators=10, n_jobs=None, num_outputs=3, oob_score=False, package_name=everywhereml.sklearn.ensemble, random_state=None, template_folder=everywhereml/sklearn/ensemble, verbose=0, warm_start=False)
 */
class Classifier {
public:

    /**
     * Predict class from features
     */
    int predict(float *x) {
        int predictedValue = 0;
        size_t startedAt = micros();



        uint16_t votes[3] = { 0 };
        uint8_t classIdx = 0;
        float classScore = 0;


        tree0(x, &classIdx, &classScore);
        votes[classIdx] += classScore;

        tree1(x, &classIdx, &classScore);
        votes[classIdx] += classScore;

        tree2(x, &classIdx, &classScore);
        votes[classIdx] += classScore;

        tree3(x, &classIdx, &classScore);
        votes[classIdx] += classScore;

        tree4(x, &classIdx, &classScore);
        votes[classIdx] += classScore;

        tree5(x, &classIdx, &classScore);
        votes[classIdx] += classScore;

        tree6(x, &classIdx, &classScore);
        votes[classIdx] += classScore;

        tree7(x, &classIdx, &classScore);
        votes[classIdx] += classScore;

        tree8(x, &classIdx, &classScore);
        votes[classIdx] += classScore;

        tree9(x, &classIdx, &classScore);
        votes[classIdx] += classScore;


        uint8_t maxClassIdx = 0;
        float maxVote = votes[0];

        for (uint8_t i = 1; i < 3; i++) {
            if (votes[i] > maxVote) {
                maxClassIdx = i;
                maxVote = votes[i];
            }
        }

        predictedValue = maxClassIdx;



        latency = micros() - startedAt;

        return (lastPrediction = predictedValue);
    }



    /**
     * Get latency in micros
     */
    uint32_t latencyInMicros() {
        return latency;
    }

    /**
     * Get latency in millis
     */
    uint16_t latencyInMillis() {
        return latency / 1000;
    }


protected:
    float latency = 0;
    int lastPrediction = 0;





    /**
     * Random forest's tree #0
     */
    void tree0(float *x, uint8_t *classIdx, float *classScore) {

        if (x[7] < -37.0) {

            if (x[2] < -32.0) {

                if (x[6] < -78.5) {

                    *classIdx = 0;
                    *classScore = 10.0;
                    return;

                }
                else {

                    *classIdx = 1;
                    *classScore = 7.0;
                    return;

                }

            }
            else {

                *classIdx = 1;
                *classScore = 7.0;
                return;

            }

        }
        else {

            if (x[8] < -38.0) {

                *classIdx = 2;
                *classScore = 12.0;
                return;

            }
            else {

                *classIdx = 0;
                *classScore = 10.0;
                return;

            }

        }

    }



    /**
     * Random forest's tree #1
     */
    void tree1(float *x, uint8_t *classIdx, float *classScore) {

        if (x[5] < -58.0) {

            if (x[2] < -76.0) {

                *classIdx = 1;
                *classScore = 2.0;
                return;

            }
            else {

                if (x[8] < -34.5) {

                    if (x[5] < -69.0) {

                        *classIdx = 0;
                        *classScore = 15.0;
                        return;

                    }
                    else {

                        *classIdx = 1;
                        *classScore = 2.0;
                        return;

                    }

                }
                else {

                    *classIdx = 0;
                    *classScore = 15.0;
                    return;

                }

            }

        }
        else {

            *classIdx = 2;
            *classScore = 12.0;
            return;

        }

    }



    /**
     * Random forest's tree #2
     */
    void tree2(float *x, uint8_t *classIdx, float *classScore) {

        if (x[2] < -32.0) {

            if (x[2] < -69.5) {

                *classIdx = 2;
                *classScore = 8.0;
                return;

            }
            else {

                *classIdx = 0;
                *classScore = 11.0;
                return;

            }

        }
        else {

            *classIdx = 1;
            *classScore = 10.0;
            return;

        }

    }



    /**
     * Random forest's tree #3
     */
    void tree3(float *x, uint8_t *classIdx, float *classScore) {

        if (x[5] < -67.5) {

            if (x[2] < -77.0) {

                *classIdx = 1;
                *classScore = 6.0;
                return;

            }
            else {

                *classIdx = 0;
                *classScore = 14.0;
                return;

            }

        }
        else {

            if (x[6] < -37.5) {

                *classIdx = 1;
                *classScore = 6.0;
                return;

            }
            else {

                *classIdx = 2;
                *classScore = 9.0;
                return;

            }

        }

    }



    /**
     * Random forest's tree #4
     */
    void tree4(float *x, uint8_t *classIdx, float *classScore) {

        if (x[6] < -37.0) {

            if (x[3] < -60.5) {

                *classIdx = 0;
                *classScore = 12.0;
                return;

            }
            else {

                *classIdx = 1;
                *classScore = 9.0;
                return;

            }

        }
        else {

            *classIdx = 2;
            *classScore = 8.0;
            return;

        }

    }



    /**
     * Random forest's tree #5
     */
    void tree5(float *x, uint8_t *classIdx, float *classScore) {

        if (x[7] < -37.0) {

            if (x[7] < -79.5) {

                *classIdx = 0;
                *classScore = 9.0;
                return;

            }
            else {

                *classIdx = 1;
                *classScore = 10.0;
                return;

            }

        }
        else {

            if (x[3] < -75.5) {

                *classIdx = 0;
                *classScore = 9.0;
                return;

            }
            else {

                *classIdx = 2;
                *classScore = 10.0;
                return;

            }

        }

    }



    /**
     * Random forest's tree #6
     */
    void tree6(float *x, uint8_t *classIdx, float *classScore) {

        if (x[10] < -72.5) {

            if (x[5] < -59.0) {

                *classIdx = 0;
                *classScore = 7.0;
                return;

            }
            else {

                *classIdx = 2;
                *classScore = 12.0;
                return;

            }

        }
        else {

            if (x[0] < -35.5) {

                if (x[8] < -32.5) {

                    *classIdx = 1;
                    *classScore = 10.0;
                    return;

                }
                else {

                    *classIdx = 0;
                    *classScore = 7.0;
                    return;

                }

            }
            else {

                *classIdx = 0;
                *classScore = 7.0;
                return;

            }

        }

    }



    /**
     * Random forest's tree #7
     */
    void tree7(float *x, uint8_t *classIdx, float *classScore) {

        if (x[3] < -60.5) {

            if (x[10] < -37.5) {

                if (x[6] < -39.5) {

                    *classIdx = 0;
                    *classScore = 8.0;
                    return;

                }
                else {

                    *classIdx = 2;
                    *classScore = 10.0;
                    return;

                }

            }
            else {

                *classIdx = 0;
                *classScore = 8.0;
                return;

            }

        }
        else {

            *classIdx = 1;
            *classScore = 11.0;
            return;

        }

    }



    /**
     * Random forest's tree #8
     */
    void tree8(float *x, uint8_t *classIdx, float *classScore) {

        if (x[3] < -60.5) {

            if (x[6] < -38.0) {

                *classIdx = 0;
                *classScore = 9.0;
                return;

            }
            else {

                if (x[10] < -38.5) {

                    *classIdx = 2;
                    *classScore = 7.0;
                    return;

                }
                else {

                    *classIdx = 0;
                    *classScore = 9.0;
                    return;

                }

            }

        }
        else {

            *classIdx = 1;
            *classScore = 13.0;
            return;

        }

    }



    /**
     * Random forest's tree #9
     */
    void tree9(float *x, uint8_t *classIdx, float *classScore) {

        if (x[10] < -72.5) {

            if (x[8] < -81.5) {

                *classIdx = 0;
                *classScore = 8.0;
                return;

            }
            else {

                *classIdx = 2;
                *classScore = 9.0;
                return;

            }

        }
        else {

            if (x[3] < -60.5) {

                *classIdx = 0;
                *classScore = 8.0;
                return;

            }
            else {

                *classIdx = 1;
                *classScore = 12.0;
                return;

            }

        }

    }




};




#endif
